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

#include "cpp_stm32/utility/bit.hxx"
#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/mmio.hxx"
#include "cpp_stm32/utility/utility.hxx"

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

template <typename BitList, typename BitListIdx, Access IoOp = Access::Word>
class Register {
 private:
	std::uint32_t const m_base;
	std::uint32_t const m_offset;

	/**
	 * This function handles MMIO operation according to Access flag
	 *
	 * @return register value
	 * @note this is written in relatively easy way, can be extended if needed
	 */
	decltype(auto) readReg() const noexcept {
		if constexpr ((to_underlying(IoOp) & to_underlying(Access::Word)) != 0) {
			return MMIO32(m_base, m_offset);
		} else if constexpr ((to_underlying(IoOp) & to_underlying(Access::HalfWord)) != 0) {
			return MMIO16(m_base, m_offset);
		} else if constexpr ((to_underlying(IoOp) & to_underlying(Access::Byte)) != 0) {
			return MMIO8(m_base, m_offset);
		}
	}

	template <BitListIdx BitIdx, typename ValueType>
	static constexpr auto IS_TYPE_AVAILABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return std::is_same_v<ValueType, typename BitType::AbstractType>;
	};

	template <BitListIdx BitIdx>
	static constexpr auto CHECK_BIT_MOD = [](BitMod const& t_check) {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return BitType::MOD == t_check;
	};

	template <BitListIdx BitIdx>
	static constexpr auto IS_BIT_WRITABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return (to_underlying(BitType::MOD) & to_underlying(BitMod::WrOnly)) != 0;
	};

	template <BitListIdx BitIdx>
	static constexpr auto IS_BIT_READABLE = []() {
		using BitType = decltype(get_bit<BitList, to_underlying(BitIdx)>());
		return (to_underlying(BitType::MOD) & to_underlying(BitMod::RdOnly)) != 0;
	};

	template <BitListIdx BitIdx>
	constexpr auto readSingleBit(ValueOnlyType /*unused*/) const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		using Ret_t				 = typename decltype(bit)::AbstractType;
		auto const ret_val = (readReg() & bit.mask) >> bit.pos;

		return static_cast<Ret_t>(ret_val);
	}

	template <BitListIdx BitIdx, BitListIdx... BitIdxList>
	static constexpr auto bitIdxOrder() noexcept {
		auto const bit_idx_list = std::array{BitIdxList...};
		return cstd::find(bit_idx_list.begin(), bit_idx_list.end(), BitIdx) - bit_idx_list.begin();
	}

	template <BitListIdx Idx>
	using ConstIdxType = std::integral_constant<BitListIdx, Idx>;

	template <BitListIdx... BitIdx>
	constexpr decltype(auto) readCurrentVal() const noexcept {
		constexpr auto need_to_read_current_val =
			((!CHECK_BIT_MOD<BitIdx>(BitMod::WrOnly) && !CHECK_BIT_MOD<BitIdx>(BitMod::RdSet)) || ...);

		if constexpr (need_to_read_current_val) {
			return readReg();
		} else {
			return 0;
		}
	}

 public:
	explicit constexpr Register(std::uint32_t const base, std::uint32_t const offset) : m_base(base), m_offset(offset) {}

	template <BitListIdx BitIdx>
	constexpr void setBit() const noexcept {
		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();

		static_assert(bit.LENGTH == 1);
		readReg() |= bit.mask;
	}

	template <BitListIdx... BitIdx, typename ValueType>
	constexpr void setBit(ValueType const& t_param) const noexcept {
		static_assert((IS_TYPE_AVAILABLE<BitIdx, ValueType>() && ...));
		static_assert((IS_BIT_WRITABLE<BitIdx>() && ...));

		const auto current_val = readCurrentVal<BitIdx...>();

		const auto mod_val		= (... | get_bit<BitList, to_underlying(BitIdx)>()(t_param));
		const auto clear_mask = ~(... | get_bit<BitList, to_underlying(BitIdx)>().mask);

		readReg() = (current_val & clear_mask) | mod_val;
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

		const auto current_val = readCurrentVal<BitIdx...>();

		const auto mod_val		= (... | mod_val_for_each_bit(ConstIdxType<BitIdx>{}, t_param));
		const auto clear_mask = ~(... | get_bit<BitList, to_underlying(BitIdx)>().mask);

		readReg() = ((current_val & clear_mask) | mod_val);
	}

	// Rethink, when do i really need this function, if really needed, maybe combine two function
	// by returning std::pair</*value*/, std::tuple<...> /*position*/> ?
	template <BitListIdx... BitIdx>
	constexpr auto readBit(ValWithPosType /*unused*/) const noexcept {
		static_assert((IS_BIT_READABLE<BitIdx>() && ...));
		constexpr auto mask = (get_bit<BitList, to_underlying(BitIdx)>().mask | ...);
		return readReg() & mask;	// perhaps return array of bit?, or creat a kind of data type?
	}

	// using std::bitset?
	template <BitListIdx... BitIdx>
	constexpr auto readBit(ValueOnlyType /*unused*/) const noexcept {
		static_assert((IS_BIT_READABLE<BitIdx>() && ...));
		return BitGroup{readSingleBit<BitIdx>(ValueOnly)...};
	}

	/**
	 * This function writes 0 to the register at bit at BitIdx
	 *
	 * @tparam BitIdx 	position of the bit
	 */
	template <BitListIdx BitIdx>
	constexpr void clearBit() const noexcept {
		static_assert(!CHECK_BIT_MOD<BitIdx>(BitMod::RdClrWr1));

		constexpr auto bit = get_bit<BitList, to_underlying(BitIdx)>();
		readReg() &= (~bit.mask);
	}
};

#define SETUP_REGISTER_INFO(Name, ...)                 \
	class Name {                                         \
		template <typename BitList, std::size_t Idx>       \
		friend constexpr auto get_bit() noexcept;          \
                                                       \
	 private:                                            \
		static constexpr std::tuple BIT_LIST{__VA_ARGS__}; \
	};
