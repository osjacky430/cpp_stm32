from formatter import RegFileMaker
from cmsis_svd.parser import SVDParser

parser = SVDParser.for_packaged_svd('STMicro', 'STM32F446x.svd')

if __name__ == '__main__':
    device = parser.get_device()

    file_maker = RegFileMaker('code_generator/result/', device)
    file_maker.create_file()
