# Cpp for STM32
A project for fun, which literally implements stm32 driver using pure c++, primarily c++17. This project is inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17."
## Some thoughts
The code is written according to my "three layers of abstraction" idea. Basically, the first layer of abstraction is to abstract the register and memory address, mainly via lambda expression, and scoped enum, respectively. The second layer of abstraction is to make those complicated bit/register operations into functions. The third layer of abstraction is to hide those complicated initializations, configurations, and destructions process inside the object.
