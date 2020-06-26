from collections import defaultdict
import os
import subprocess

CPP_STM32_BIT_HXX = 'cpp_stm32/hal/bit.hxx'
CPP_STM32_REG_HXX = 'cpp_stm32/hal/register.hxx'


class FieldMaker:
    ACCESS_TABLE = {
        'read-write': 'BitMod::RdWr',
        'read-only': 'BitMod::RdOnly',
        'write-only': 'BitMod::WrOnly',
        None: 'BitMod::RdWr'
    }

    def __constructor(self):
        return '{' + self.bit_offset_str + '}'

    def __template(self):
        template_param = '<'

        if self.type_str == 'Binary':
            if self.access_str != 'BitMod::RdWr':
                template_param += self.access_str
        elif self.type_str == 'StatusBit':
            template_param += self.bit_width_str

            if self.data_type != 'std::uint8_t':
                template_param += self.data_type
        else:
            template_param += self.bit_width_str

            if self.data_type != 'std::uint8_t':
                template_param += ', ' + self.data_type

            if self.access_str != 'BitMod::RdWr':
                template_param += ', ' + self.access_str

        template_param += '>'
        return template_param

    def __init__(self, bit_width: int, bit_offset: int, access: str):
        self.bit_width_str = str(bit_width)
        self.bit_offset_str = 'BitPos_t{%s}' % bit_offset
        self.access_str = self.ACCESS_TABLE[access]

        if access == 'read-only':
            self.type_str = 'StatusBit'
        else:
            if bit_width == 1:
                self.type_str = 'Binary'
            else:
                self.type_str = 'Bit'

        if bit_width <= 8:
            self.data_type = 'std::uint8_t'
        elif 8 < bit_width <= 16:
            self.data_type = 'std::uint16_t'
        else:
            self.data_type = 'std::uint32_t'

    def __str__(self):
        return self.type_str + self.__template() + self.__constructor()


class RegFileMaker:
    def __init__(self, output_path, device):
        os.chdir(output_path)

        self.device = device
        self.peripheral_address = self.__group_periph_addr()

        if self.device.cpu == 'CM4':
            pass

        self.file = None

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.file.close()

    def __group_periph_addr(self):
        result = defaultdict(list)
        peripheral_address_map = [(periph.group_name, (periph.base_address, periph.name))
                                  for periph in self.device.peripherals]

        for group_name, port_addr_map in peripheral_address_map:
            result[group_name].append(port_addr_map)

        return result

    def __define_guard(self):
        define_guard = '#pragma once\n\n'
        self.file.write(define_guard)

    def __include(self, directory):
        include = '#include "%s"\n' % directory
        self.file.write(include)

    def __start_namespace(self, peripheral):
        start_namespace_str = '\n' + 'namespace cpp_stm32::%s::reg {\n\n' % peripheral.group_name.lower()
        self.file.write(start_namespace_str)

    def __end_namespace(self, peripheral):
        end_namespace_str = '\n} // cpp_stm32::%s::reg\n' % peripheral.group_name.lower()
        self.file.write(end_namespace_str)

    def __start_doc_group(self, peripheral_name: str, register_name: str, description: str):
        doc_str = '/**\n' \
               ' * @defgroup\t%s_%s_GROUP\t\t%s group\n'\
               ' *\n' \
               ' * @{\n' \
               ' */\n\n' % (peripheral_name, register_name, ' '.join(description.split()))
        self.file.write(doc_str)

    def __end_doc_group(self):
        doc_str = '\n/**@}*/\n\n'
        self.file.write(doc_str)

    def __add_index_enum(self, register):
        enum_str = 'enum class %sField {\n' % register.name

        for field in self.grouped_field:
            doc_str = ' '.join(field.description.split())
            enum_str += '\t%s,\t\t/*!< %s*/\n' % (field.name, doc_str)
        enum_str += '};\n\n'

        self.file.write(enum_str)
        return '%sField' % register.name

    def __add_field(self, register):
        self.file.write('SETUP_REGISTER_INFO(%sBitList, /**/\n\t\t\t\t\t' % register.name)
        for field in self.grouped_field:
            if not field.is_reserved:
                bit = str(FieldMaker(field.bit_width, field.bit_offset, field.access))
                if field != self.grouped_field[-1]:
                    bit += ','
                bit += '\t// %s\n\t\t\t\t\t' % field.name
                self.file.write(bit)

        self.file.write(')\n\n')

    def __group_field_by_description(self, fields):
        all_descriptions = [field.description for field in fields]
        filtered_descriptions = []
        self.grouped_field = []

        for field in reversed(fields):
            if field.description not in filtered_descriptions:
                filtered_descriptions.append(field.description)
                repeated_description = all_descriptions.count(field.description)
                new_field = field

                if repeated_description > 1:
                    new_field.bit_width = repeated_description
                    new_field.name = new_field.name[:-1]
                self.grouped_field.append(new_field)

    def __add_register(self, peripheral, register):
        self.__start_doc_group(peripheral.name, register.name, register.description)

        if peripheral.group_name == 'GPIO':
            self.grouped_field = register.fields
            self.__add_field(register)
            idx_str = 'Pin'
        else:
            self.__group_field_by_description(register.fields)
            self.__add_field(register)
            idx_str = self.__add_index_enum(register)

        if len(self.peripheral_address[peripheral.group_name]) != 1:
            register_type_str = 'template <Port %s>\n' % peripheral.group_name
            register_type_str += 'static constexpr Register<{}BitList, {}> {}{{BASE_ADDR({}), 0x{:02x}U}};' \
                .format(register.name, idx_str, register.name, peripheral.group_name, register.address_offset)
        else:
            register_type_str = 'static constexpr Register<%sBitList, %s> %s{%s, 0x%02xU};' \
                                 % (register.name, idx_str, register.name, 'BASE_ADDR', register.address_offset)

        self.file.write(register_type_str)
        self.__end_doc_group()

    def __define_base_address(self, peripheral):
        addr_port_list = self.peripheral_address[peripheral.group_name]
        base_address_str = 'static constexpr auto BASE_ADDR'

        if len(addr_port_list) == 1:
            base_address_str += ' = 0x%08xU;\n\n' % addr_port_list[0][0]
        else:
            base_address_str += '(Port const& t_{}) {{\n' \
                                '\tswitch(t_{}) {{\n'.format(peripheral.group_name.lower(),
                                                             peripheral.group_name.lower())
            for addr, port in addr_port_list:
                base_address_str += '\tcase Port::{}:\n' \
                                    '\t\treturn 0x{:08x}U;\n'.format(port, addr)
            base_address_str += '}\n\t}\n\n'

        self.file.write(base_address_str)

    def __gen_reg_file(self, peripheral):
        self.__define_guard()

        self.__include(CPP_STM32_BIT_HXX)
        self.__include(CPP_STM32_REG_HXX)

        self.__start_namespace(peripheral)
        self.__define_base_address(peripheral)

        for register in peripheral.registers:
            self.__add_register(peripheral, register)

        self.__end_namespace(peripheral)

    def create_file(self, format=False):
        for peripheral in self.device.peripherals:
            filename = peripheral.group_name.lower() + '.hxx'

            with open(filename, 'w+') as self.file:   
                self.__gen_reg_file(peripheral)
                if format:
                    subprocess.run(['clang-format', '-i', '--style=file', filename])
