/**
 * @Date:   2019-11-22T23:14:44+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: scb.hpp
 * @Last modified time: 2019-11-23T23:53:01+08:00
 */

#ifndef SCB_HPP_
#define SCB_HPP_

class [[gnu::packed]] ScbExceptionStackFrame {
	std::uint32_t r0;
	std::uint32_t r1;
	std::uint32_t r2;
	std::uint32_t r3;
	std::uint32_t r4;
	std::uint32_t r12;
	std::uint32_t lr;
	std::uint32_t pc;
	std::uint32_t xpsr;
};

constexpr void scb_set_priority_grouping() noexcept {}

#endif SCB_HPP_
