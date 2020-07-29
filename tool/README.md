## Code Generator
The code generator generates header files for the chip from the svd file supplied by the vendor. This is a faster way to create register header files. However, svd file may have (a lot of) mistakes in it, therefore the generated headers need to be double checked before using them.
### Usage
Print help information:
```
run_code_gen.py --help
```
