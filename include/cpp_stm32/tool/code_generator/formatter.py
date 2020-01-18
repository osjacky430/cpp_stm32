import os

CPP_STM32_BIT_HXX = 'cpp_stm32/hal/bit.hxx'
CPP_STM32_REG_HXX = 'cpp_stm32/hal/register.hxx'


class FieldMaker:
    ACCESS_TABLE = {
        'read-write': 'BitMod::RdWr',
        'read-only': 'BitMod::RdOnly',
        'write-only': 'BitMod::WrOnly',
        None: 'BitMod::RdWr'
    }

    def __init__(self, bit_width: int, bit_offset: int, access: str, name: str):
        self.bit_width_str = str(bit_width)
        self.bit_offset_str = str(bit_offset)
        self.access_str = self.ACCESS_TABLE[access]

        # if bit_width > 1


class RegFileMaker:
    def __init__(self, output_path, peripheral):
        os.chdir(output_path)

        self.peripheral = peripheral
        self.peripheral_address = [peripheral.base_address]
        self.name = peripheral.group_name
        self.grouped_field = []
        self.filename = self.name.lower() + '_reg.hxx'

    def __enter__(self):
        self.file = open(self.filename, 'w+')
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.file.close()

    def __define_guard(self):
        define_guard = '#pragma once\n\n'
        self.file.write(define_guard)

    def __include(self, directory):
        include = '#include "%s"\n' % directory
        self.file.write(include)

    def __start_namespace(self):
        start_namespace_str = '\n' + 'namespace cpp_stm32::%s::reg {\n\n' % self.name.lower()
        self.file.write(start_namespace_str)

    def __end_namespace(self):
        end_namespace_str = '\n} // cpp_stm32::%s::reg\n' % self.name.lower()
        self.file.write(end_namespace_str)

    def __start_doc_group(self, register_name: str, description: str):
        doc_str = '/**\n' \
               ' * @defgroup\t%s_%s_GROUP\t\t%s group\n'\
               ' *\n' \
               ' * @{\n' \
               ' */\n\n' % (self.peripheral.name, register_name, ' '.join(description.split()))
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

    def __add_field(self, field):
        access = field.access
        pass

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

    def __add_register(self, register):

        self.__group_field_by_description(register.fields)
        self.__start_doc_group(register.name, register.description)

        self.__add_index_enum(register)

        self.__add_field(register)

        register_type_str = 'static constexpr Register<, %s> %s{BASE_ADDR, 0x%02xU};' % (register.name + 'Field', register.name,
                                                                                register.address_offset)
        self.file.write(register_type_str)
        self.__end_doc_group()

    def __define_base_address(self):
        base_address_str = 'static constexpr auto BASE_ADDR = '
        if len(self.peripheral_address) == 1:
            base_address_str += '0x%08xU' % self.peripheral_address[0]
        else:
            pass
        base_address_str += ';\n\n'
        self.file.write(base_address_str)

    def create_file(self):
        self.__define_guard()

        self.__include(CPP_STM32_BIT_HXX)
        self.__include(CPP_STM32_REG_HXX)

        self.__start_namespace()
        self.__define_base_address()

        for register in self.peripheral.registers:
            self.__add_register(register)

        self.__end_namespace()
