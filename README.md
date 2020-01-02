# Cpp for STM32
A project for fun, which literally implements stm32 driver using pure c++, primarily c++17. This project is inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17."
## Recent ideas
Since there are alot of things going on here, I need to make a list of recent ideas in order to remember the though process and current progress.
- Find a suitable file structure so that it is relatively easy to extend to other targets
- Put common function in "hal" file  
- Group common registers (see "common" file in target/stm32/), however, some registers despite having same name and functionality, the register position may be different. Therefore, some need special care, whereas others don't, but this may leads to inconsistency, still finding a better way of dealing it. 
## Compiler in use
I'm using two versions of compiler on different computers, one is arm-none-eabi-g++ 20190703 release, and arm-none-eabi-g++ <del>20180622 release</del> 20191025 release, currently, formal compiler works pretty well, the later seems to have some issues <del>and are still resolving</del> (I give up 20180622 release, due to the internal compiler error).
