/**
 * @Date:   2019-12-10T21:40:46+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: register.hpp
 */

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>

#include "include/hal/bit/bit.hxx"
#include "include/hal/utility.hxx"

template <typename BitList, std::size_t Idx>
static constexpr auto get_bit() noexcept {
	return std::get<Idx>(BitList::BIT_LIST);
}

// tag dispatch for readBit function
struct ValueOnlyType {
	ValueOnlyType() = default;
};
static constexpr ValueOnlyType ValueOnly{};

struct ValWithPosType {
	ValWithPosType() = default;
};
static constexpr ValWithPosType ValWithPos{};

template <typename BitList, typename BitListIdx>
class Register {
 private:
	std::uint32_t const m_base;
	std::uint32_t const m_offset;

	template <BitListIdx BitIdx, typename ValueType>
	static constexpr auto IS_TYPE_AVAILABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return std::is_same_v<ValueType, typename BitType::AbstractType>;
	};

	template <BitListIdx BitIdx>
	static constexpr auto IS_BIT_WRITABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return (to_underlying(BitType::MOD) & to_underlying(BitMod::WriteOnly)) != 0;
	};

	template <BitListIdx BitIdx>
	static constexpr auto IS_BIT_READABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return (to_underlying(BitType::MOD) & to_underlying(BitMod::ReadOnly)) != 0;
	};

	template <BitListIdx BitIdx>
	constexpr auto readSingleBit(ValueOnlyType /*unused*/) const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		using Ret_t				 = typename decltype(bit)::AbstractType;
		auto const ret_val = (MMIO32(m_base, m_offset) & bit.mask) >> bit.pos;

		return static_cast<Ret_t>(ret_val);
	}

	template <BitListIdx BitIdx, BitListIdx... BitIdxList>
	static constexpr auto bitIdxOrder() noexcept {
		auto const bit_idx_list = std::array{BitIdxList...};
		return constexpr_std_find(bit_idx_list.begin(), bit_idx_list.end(), BitIdx) - bit_idx_list.begin();
	}

	template <BitListIdx Idx>
	using ConstIdxType = std::integral_constant<BitListIdx, Idx>;

 public:
	explicit constexpr Register(std::uint32_t const base, std::uint32_t const offset) : m_base(base), m_offset(offset) {}

	template <BitListIdx BitIdx>
	constexpr void setBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();

		static_assert(bit.LENGTH == 1);
		MMIO32(m_base, m_offset) |= bit.mask;
	}

	template <BitListIdx... BitIdx, typename ValueType>
	constexpr void setBit(ValueType const& t_param) const noexcept {
		static_assert((IS_TYPE_AVAILABLE<BitIdx, ValueType>() && ...));
		static_assert((IS_BIT_WRITABLE<BitIdx>() && ...));

		const auto current_val = ((IS_BIT_READABLE<BitIdx>() || ...) ? MMIO32(m_base, m_offset) : 0);

		const auto mod_val		= (... | get_bit<BitList, to_underlying(BitIdx)>()(t_param));
		const auto clear_mask = ~(... | get_bit<BitList, to_underlying(BitIdx)>().mask);

		MMIO32(m_base, m_offset) = (current_val & clear_mask) | mod_val;
	}

	template <BitListIdx... BitIdx, typename... ValueTypes>
	constexpr void setBit(BitGroup<ValueTypes...> const& t_param) const noexcept {
		static_assert(sizeof...(BitIdx) == sizeof...(ValueTypes));
		static_assert((IS_TYPE_AVAILABLE<BitIdx, ValueTypes>() && ...));
		static_assert((IS_BIT_WRITABLE<BitIdx>() && ...));

		constexpr auto mod_val_for_each_bit = [](auto const& t_bit_idx, auto const& t_param) {
			constexpr auto bit		= get_bit<BitList, to_underlying(t_bit_idx())>();
			const auto val_to_mod = get<bitIdxOrder<t_bit_idx(), BitIdx...>()>(t_param);
			return bit(val_to_mod);
		};

		const auto current_val = ((IS_BIT_READABLE<BitIdx>() || ...) ? MMIO32(m_base, m_offset) : 0);

		const auto mod_val		= (... | mod_val_for_each_bit(ConstIdxType<BitIdx>{}, t_param));
		const auto clear_mask = ~(... | get_bit<BitList, to_underlying(BitIdx)>().mask);

		MMIO32(m_base, m_offset) = ((current_val & clear_mask) | mod_val);
	}

	// Rethink, when do i really need this function, if really needed, maybe combine two function
	// by returning std::pair</*value*/, std::tuple<...> /*position*/> ?
	template <BitListIdx... BitIdx>
	constexpr auto readBit(ValWithPosType /*unused*/) const noexcept {
		static_assert((IS_BIT_READABLE<BitIdx>() && ...));
		constexpr auto mask = (get_bit<BitList, to_underlying(BitIdx)>().mask | ...);
		return MMIO32(m_base, m_offset) & mask;	 // perhaps return array of bit?, or creat a kind of data type?
	}

	// using std::bitset?
	template <BitListIdx... BitIdx>
	constexpr auto readBit(ValueOnlyType /*unused*/) const noexcept {
		static_assert((IS_BIT_READABLE<BitIdx>() && ...));
		return BitGroup{readSingleBit<BitIdx>(ValueOnly)...};
	}

	template <BitListIdx BitIdx>
	constexpr void clearBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		MMIO32(m_base, m_offset) &= (~bit.mask);
	}

	decltype(auto) readReg() const noexcept { return MMIO32(m_base, m_offset); }
};
