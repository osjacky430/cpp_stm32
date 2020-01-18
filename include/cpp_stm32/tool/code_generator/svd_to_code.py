import os
from formatter import RegFileMaker
from cmsis_svd.parser import SVDParser

parser = SVDParser.for_packaged_svd('STMicro', 'STM32F446x.svd')


def main():
    device = parser.get_device()
    for peripheral in parser.get_device().peripherals:
        # print(peripheral.group_name)
        if peripheral.name == 'RCC':
            with RegFileMaker('code_generator/result/', peripheral) as file_maker:
                file_maker.create_file()


if __name__ == '__main__':
    main()
