#pragma once

#include <cstdint>

namespace cpp_stm32 {

template <std::uint32_t Q, typename Tag>
struct Unit {
	constexpr auto operator()() const noexcept { return Q; }
};

template <std::uint32_t LHS, std::uint32_t RHS, typename Tag>
constexpr bool operator>(Unit<LHS, Tag> const&, Unit<RHS, Tag> const&) noexcept {
	return LHS > RHS;
}

template <std::uint32_t LHS, std::uint32_t RHS, typename Tag>
constexpr bool operator>=(Unit<LHS, Tag> const&, Unit<RHS, Tag> const&) noexcept {
	return LHS >= RHS;
}

template <std::uint32_t LHS, std::uint32_t RHS, typename Tag>
constexpr bool operator<(Unit<LHS, Tag> const&, Unit<RHS, Tag> const&) noexcept {
	return LHS < RHS;
}

template <std::uint32_t LHS, std::uint32_t RHS, typename Tag>
constexpr bool operator<=(Unit<LHS, Tag> const&, Unit<RHS, Tag> const&) noexcept {
	return LHS <= RHS;
}

template <std::uint32_t LHS, std::uint32_t RHS, typename Tag>
constexpr bool operator==(Unit<LHS, Tag> const&, Unit<RHS, Tag> const&) noexcept {
	return LHS == RHS;
}

template <std::uint32_t LHS, std::uint32_t RHS, typename Tag>
constexpr bool operator!=(Unit<LHS, Tag> const&, Unit<RHS, Tag> const&) noexcept {
	return LHS != RHS;
}

}	// namespace cpp_stm32
