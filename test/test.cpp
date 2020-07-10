#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_NO_POSIX_SIGNALS

#include "catch2/catch.hpp"

#include <sys/signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cerrno>
#include <cstdlib>

void* __dso_handle = (void*)&__dso_handle;

[[gnu::always_inline]] inline auto get_stack_ptr() noexcept {
	std::uint32_t stack_ptr = 0;
	__asm volatile("mrs %0, msp" : "=r"(stack_ptr));

	return stack_ptr;
}

extern "C" void* _sbrk(ptrdiff_t t_increment) {
	extern unsigned heap_start_;
	static unsigned* heap_end_ = &heap_start_;

	unsigned* previous_heap_end = heap_end_;
	unsigned* stack_address			= (unsigned*)get_stack_ptr();

	if (heap_end_ + t_increment > stack_address) {
		// _write(STDERR_FILENO, "Heap and stack collision\n", 25);
		errno = ENOMEM;

		return NULL;
	}

	heap_end_ += t_increment;
	return previous_heap_end;
}
