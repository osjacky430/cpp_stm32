#include <cstdint>
#include <cstdio>

#include "cpp_stm32/redirect/sys_call.hxx"

static unsigned char const* file_name;

extern "C" void __gcov_exit(void);

/**
 * [_exit description]
 * @param t_status [description]
 */
extern "C" __attribute__((noreturn)) void _exit(__attribute__((unused)) int t_status) {
	__gcov_exit();

	while (true) {
	}
}

/**
 * [_kill description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _kill(__attribute__((unused)) pid_t t_pid, __attribute__((unused)) int t_sig) {
	errno = EINVAL;
	return (-1);
}

/**
 * [_wirte description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _write(__attribute__((unused)) int t_file, const void* t_ptr, size_t t_len) { return (int)t_len; }

/**
 * [_open description]
 * @param  t_ptr  [description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _open(char const* t_ptr, __attribute__((unused)) int t_mode) {
	file_name = (unsigned char const*)t_ptr;
	return 0;
}

/**
 * [_close description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _close(__attribute__((unused)) int t_file) { return 0; }

/**
 * [_read description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _read(__attribute__((unused)) int file, __attribute__((unused)) void* ptr,
										 __attribute__((unused)) size_t len) {
	return 0;
}

/**
 * [_fstat description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _fstat(__attribute__((unused)) int t_file, struct stat* t_st) {
	t_st->st_mode = S_IFCHR;
	return 0;
}

/**
 * [_getpid description]
 * @return  [description]
 */
extern "C" int _getpid(void) { return 1; }

/**
 * [_isatty description]
 * @param  file [description]
 * @return      [description]
 */
extern "C" int _isatty(int file) {
	switch (file) {
		case STDOUT_FILENO:
		case STDERR_FILENO:
		case STDIN_FILENO:
			return 1;
		default:
			errno = EBADF;
			return 0;
	}
}

/**
 * [_lseek description]
 * @param  unused [description]
 * @return        [description]
 */
extern "C" int _lseek(__attribute__((unused)) int file, __attribute__((unused)) _off_t ptr,
											__attribute__((unused)) int dir) {
	return 0; /* return offset in file */
}

/**
 * [get_stack_ptr description]
 * @return [description]
 */
[[gnu::always_inline]] inline auto get_stack_ptr() noexcept {
	std::uint32_t stack_ptr = 0;
	__asm volatile("mrs %0, msp" : "=r"(stack_ptr));

	return stack_ptr;
}

/**
 * [_sbrk description]
 */
extern "C" void* _sbrk(ptrdiff_t t_increment) {
	extern unsigned heap_start_;
	static unsigned* heap_end_ = &heap_start_;

	unsigned* previous_heap_end = heap_end_;
	unsigned* stack_address			= (unsigned*)get_stack_ptr();

	if (heap_end_ + t_increment > stack_address) {
		_write(STDERR_FILENO, "Heap and stack collision\n", 25);
		errno = ENOMEM;

		return NULL;
	}

	heap_end_ += t_increment;
	return previous_heap_end;
}
