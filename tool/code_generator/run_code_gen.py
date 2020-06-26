from formatter import RegFileMaker
from cmsis_svd.parser import SVDParser
from pathlib import Path
import argparse
import subprocess

arg_parser = argparse.ArgumentParser()
arg_parser.add_argument('vendor', help='microcontroller vendor')
arg_parser.add_argument('target', help='target microcontroller')
arg_parser.add_argument('--output', help='output directory')
arg_parser.add_argument('--format', help='format resulting files with clang-format', action='store_true')

cmd_input = arg_parser.parse_args()

OUTPUT_DIR = 'result/'

parser = SVDParser.for_packaged_svd(cmd_input.vendor, cmd_input.target + '.svd')

if __name__ == '__main__':
    device = parser.get_device()
   
    output = OUTPUT_DIR + cmd_input.target if cmd_input.output is None else cmd_input.output

    Path(output).mkdir(parents=True, exist_ok=True)
    file_maker = RegFileMaker(output,  device)
    file_maker.create_file(cmd_input.format)

