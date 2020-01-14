# Cpp for STM32
A project for fun, which literally implements stm32 driver using pure c++, primarily c++17. This project is inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17."
## Recent ideas
Since there are alot of things going on here, I need to make a list of recent ideas in order to remember the though process and current progress.
- [https://www.youtube.com/watch?v=fsMmh8F8uV0] (This awesome talk), thread safety needs to be investigated in the future, as for now I don't have much knowledge regarding this part.
- The implementation of interrupt is not so satisfying, but can't come up with a better idea so far.
- Group common registers (see "common" file in target/stm32/), however, some registers despite having same name and functionality, the register position may be different. Therefore, some need special care, whereas others don't, but this may leads to inconsistency, still finding a better way of dealing it. (Update: this is not applicable, it makes newcomer hard to make contribution since not all the things is grouped together, in order to make contribution easier, every mcu should be considered separately)

## Compiler in use
I'm using two versions of compiler on different computers, one is arm-none-eabi-g++ 20190703 release, and arm-none-eabi-g++ <del>20180622 release</del> 20191025 release, currently, formal compiler works pretty well, the later seems to have some issues <del>and are still resolving</del> (I give up 20180622 release, due to the internal compiler error).
