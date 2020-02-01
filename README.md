# Cpp for STM32
A project for fun, which literally implements stm32 driver using pure c++, primarily c++17. This project is inspired by Jason Turner's talk "Rich Code for Tiny Computers: A Simple Commodore 64 Games in C++17."
## Recent ideas
Since there are alot of things going on here, I need to make a list of recent ideas in order to remember the thought process and current progress.
- Thread safety (i.e. concurrency, race condition) needs to be investigated in the future, as for now I don't have much knowledge regarding this part.
- The implementation of interrupt is not so satisfying, but can't come up with a better idea so far.
## References
- [Odin Holmes “Concurrency Challenges of Interrupt Service Routines”](https://www.youtube.com/watch?v=gcRdG7dGMOw)
- [A Possible Future of Embedded Software Development - Odin Holmes](https://www.youtube.com/watch?v=fsMmh8F8uV0)
- [Jason Turner “Rich Code for Tiny Computers: A Simple Commodore 64 Game in C++17”](https://www.youtube.com/watch?v=zBkNBP00wJE)
- [Writing better embedded Software - Dan Saks](https://www.youtube.com/watch?v=3VtGCPIoBfs&t=2123s)
- [Modern C++ in Embedded Systems](https://www.youtube.com/watch?v=1l2g2dAobXA)
- [CppCon 2018: Michael Caisse “Modern C++ in Embedded Systems - The Saga Continues”](https://www.youtube.com/watch?v=LfRLQ7IChtg)
