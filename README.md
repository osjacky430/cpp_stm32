# Cpp for STM32
A project for fun, which literally implements stm32 driver using pure c++, primarily c++17. This project is inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17."
## Some thoughts
The code is written according to my "three layers of abstraction" idea. Basically, the first layer of abstraction is to abstract the register and memory address, mainly via lambda expression, and scoped enum, respectively. The second layer of abstraction is to make those complicated bit/register operations into functions. The third layer of abstraction is to hide those complicated initializations, configurations, and destructions process inside the object.
## Some other thoughts
The thoughts above change rapidly cause I'm trying all kinds of things that comes up in my head, but I'll stick to the idea mentioned previously, the thing that will change is the way I implemented.
## Recent ideas
Since there are alot of things going on here, I need to make a list of recent ideas in order to remember the though process and current progress.
- using hxx for library header: since the library needs user configuration header files, in order not have header file name collisions, adopting this idea may solve this problem.
- Using two classes `Register` and `Bit` as the abstraction of real register and bit: To exploit the advantage of type safety profile of c++, class `Register` is a templated class that takes a list of type as the available input for bitwise operation, by doing so, there is no way to set bit in register wrong. This is currently implemented by scoped enum, which leads to some problems since it carries a little information. Therefore, I am considering using second class `Bit` to carry the information of the bit, not sure what problem will encouter though.
- Add "Access" flag to `Register` to ensure correct MMIO operation.
- Attach interrupt by assigning function pointer to extern variable `irq_vector_table`
- Using `std::byte` for MMIO operation
## Compiler in use
I'm using two versions of compiler on different computers, one is arm-none-eabi-g++ 20190703 release, and arm-none-eabi-g++ 20180622 release, currently, formal compiler works pretty well, the later seems to have some issues and are still resolving.
