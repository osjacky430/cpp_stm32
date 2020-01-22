// Copyright (c) 2020 by osjacky430.
// All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the Lesser GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// Lesser GNU General Public License for more details.
//
// You should have received a copy of the Lesser GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <utility>

#include "cpp_stm32/hal/bit.hxx"
#include "cpp_stm32/hal/mmio.hxx"
#include "cpp_stm32/utility/constexpr_algo.hxx"
#include "cpp_stm32/utility/integral_constant.hxx"
#include "cpp_stm32/utility/utility.hxx"

namespace cpp_stm32 {

/**
 * @enum 	Access
 */
enum class Access { Word = 0b100, HalfWord = 0b010, Byte = 0b001 };

/**
 * @brief		This function handles OR operator of #Access
 * @param  	lhs		Left hand side
 * @param 	rhs 	Right hand side
 * @return 	Numeric value of OR operation of lhs and rhs
 */
constexpr auto operator|(Access const& lhs, Access const& rhs) {
	return Access{to_underlying(lhs) | to_underlying(rhs)};
}

/**
 * @brief		This function handles OR operator of #Access
 * @param  	lhs		Left hand side
 * @param 	rhs 	Right hand side
 * @return 	Numeric value of OR operation of lhs and rhs
 */
constexpr auto& operator|=(Access& lhs, Access rhs) {
	lhs = lhs | rhs;
	return lhs;
}

/**
 * @brief		This function is getter for bit list in bit
 * @tparam	BitList		List of bit.
 * @tparam	Idx 			Index of the bit in bit list.
 * @return  See @ref Bit.
 */
template <typename BitList, std::size_t Idx>
[[nodiscard]] static constexpr auto get_bit() noexcept {
	return std::get<Idx>(BitList::BIT_LIST);
}

/**
 * @class 	ValueOnlyType
 * @brief		Tag dispatch for @ref Register::readBit() function, value only type indicate that the readbit function
 * 					should return only the value, not including the position it is at in the register.
 *
 */
struct ValueOnlyType {};
static constexpr ValueOnlyType ValueOnly{};

/**
 * @class 	ValueWithPosType
 * @brief		Tag dispatch for @ref Register::readBit() function, val with pos type indicate that the readbit function
 * 					should return not only the value, but also the position it is at in the register.
 */
struct ValWithPosType {};
static constexpr ValWithPosType ValWithPos{};

/**
 * @class 	Register
 * @brief		This class is abstraction of register.
 * @tparam  BitList			List of bit in the register, see @ref Bit
 * @tparam	BitListIdx	The way to index through the list of bit, this should be a scoped enum.
 * @tparam	Access			Access flag indicating whicj MMIO operation is suitable to read/write
 *
 * @note		Need to add some sfinae or static_assert to ensure the user don't mess up with it
 */
template <typename BitList, typename BitListIdx, Access IoOp = Access::Word | Access::HalfWord | Access::Byte,
					bool atomicity = false>
class Register {
 private:
	template <BitListIdx Idx>
	static constexpr auto GET_BIT = get_bit<BitList, to_underlying(Idx)>;

	template <BitListIdx... Idx>
	using IsolateFrom_t = std::integer_sequence<BitListIdx, Idx...>;

	std::uint32_t const m_base;		/*!< Peripheral base address */
	std::uint32_t const m_offset; /*!< Offset relative to peripheral base */

	/**
	 * @brief		This function handles MMIO operation according to Access flag
	 * @return 	Register value
	 * @note 		This is written in relatively easy way, can be extended if needed
	 */
	constexpr decltype(auto) readReg() const noexcept {
		if constexpr ((to_underlying(IoOp) & to_underlying(Access::Word)) != 0) {
			return MMIO32(m_base, m_offset);
		} else if constexpr ((to_underlying(IoOp) & to_underlying(Access::HalfWord)) != 0) {
			return MMIO16(m_base, m_offset);
		} else if constexpr ((to_underlying(IoOp) & to_underlying(Access::Byte)) != 0) {
			return MMIO8(m_base, m_offset);
		}
	}

	template <BitListIdx... Idx, Access IoMode = Access::Byte>
	static constexpr auto viewRegByAccessMode() noexcept {
		if constexpr (IoMode == Access::Byte) {
			std::array<bool, 4> ret_val{false, false, false, false};
			((ret_val[GET_BIT<Idx>().pos / 8U] = true, ret_val[(GET_BIT<Idx>().pos + GET_BIT<Idx>().LENGTH - 1) / 8U] = true),
			 ...);
			return ret_val;
		} else if constexpr (IoMode == Access::HalfWord) {
			std::array<bool, 2> ret_val{false, false};
			((ret_val[GET_BIT<Idx>().pos / 16U]																= true,
				ret_val[(GET_BIT<Idx>().pos + GET_BIT<Idx>().LENGTH - 1) / 16U] = true),
			 ...);
			return ret_val;
		} else {
			return std::array{true};
		}
	}

	/**
	 * [decltype description]
	 * @return      [description]
	 */
	template <BitListIdx... Idx, bool must_thread_safe = false>
	constexpr decltype(auto) readReg() const noexcept {
		constexpr auto mod_byte_n = viewRegByAccessMode<Idx...>();

		constexpr auto last_byte_to_mod = [=]() {
			for (int i = 3; i >= 0; --i) {
				if (mod_byte_n[i]) return i;
			}
		}();
		constexpr bool mod_only_byte_0 = (last_byte_to_mod == 0);

		if constexpr (must_thread_safe) {
		} else {
			// note: not sure if there is performance difference regarding the speed
			//  		 of byte, half word, word access.

			// note: The following code generate this kind of strange op:
			//
			// 			8000380:	f423 53b0 	bic.w	r3, r3, #5632	; 0x1600
			// 			8000384:	041b      	lsls	r3, r3, #16
			// 			8000386:	0c1b      	lsrs	r3, r3, #16
			// 			8000388:	8013      	strh	r3, [r2, #0]

			// if constexpr ((to_underlying(IoOp) & to_underlying(Access::Byte)) != 0 && mod_only_byte_0) {
			// 	return MMIO8(m_base, m_offset);
			// } else if constexpr (constexpr bool mod_byte_01 = (last_byte_to_mod == 1);
			// 										 (to_underlying(IoOp) & to_underlying(Access::HalfWord)) != 0 && mod_byte_01) {
			// 	return MMIO16(m_base, m_offset);
			// } else {
			// 	return MMIO32(m_base, m_offset);
			// }

			// meanwhile, the following code generate this op:
			//
			//	 		8000380:	f423 53b0 	bic.w	r3, r3, #5632	; 0x1600
			// 			8000384:	6013      	str	r3, [r2, #0]
			//
			// as for reason why, still investigating...
			return readReg();
		}
	}

	/**
	 * @brief		This function check if the type of the value to be set to is valid
	 * @tparam 	BitIdx			The bit to be set in the register
	 * @tparam 	ValueType		The type of the value to be set to
	 * @rerturn	true if the type matches with the bit, false otherwise.
	 */
	template <BitListIdx BitIdx, typename ValueType>
	static constexpr auto IS_TYPE_AVAILABLE = []() {
		using BitType = decltype(GET_BIT<BitIdx>());
		return std::is_same_v<ValueType, typename BitType::AbstractType>;
	};

	/**
	 * @brief		This function checks if the bit mode of the bit equals the input bitmod
	 * @tparam 	BitIdx 		The bit to be checked in the register
	 * @param		t_check		see @ref BitMod
	 * @return 	true if two bitmods are equal, false otherwise.
	 */
	template <BitListIdx BitIdx>
	static constexpr auto CHECK_BIT_MOD = [](BitMod const& t_check) {
		using BitType = decltype(GET_BIT<BitIdx>());
		return BitType::MOD == t_check;
	};

	/**
	 * @brief		This function checks if the bit mode of the bit is writable
	 * @tparam 	BitIdx		The bit to be checked in the register.
	 * @return 	true if bitmod is writable, false otherwise.
	 */
	template <BitListIdx BitIdx>
	static constexpr auto IS_BIT_WRITABLE = []() {
		using BitType = decltype(GET_BIT<BitIdx>());
		return (to_underlying(BitType::MOD) & to_underlying(BitMod::WrOnly)) != 0;
	};

	/**
	 * @brief		This function checks if the bit mode of the bit is readable
	 * @tparam 	BitIdx 		The bit to be checked in the register.
	 * @return 	true if bitmod is readable, false otherwise.
	 */
	template <BitListIdx BitIdx>
	static constexpr auto IS_BIT_READABLE = []() {
		using BitType = decltype(GET_BIT<BitIdx>());
		return (to_underlying(BitType::MOD) & to_underlying(BitMod::RdOnly)) != 0;
	};

	/**
	 * @brief		This function reads single bit.
	 * @tparam 	BitIdx 					The bit to be read in the register.
	 * @return	The value of the bit
	 */
	template <BitListIdx BitIdx, typename T>
	constexpr auto extractBitValue(T const& t_val) const noexcept {
		constexpr auto bit = GET_BIT<BitIdx>();
		using Ret_t				 = typename decltype(bit)::AbstractType;
		auto const ret_val = (t_val & bit.mask) >> bit.pos;

		return static_cast<Ret_t>(ret_val);
	}

	/**
	 * @brief		This function count the index of the BitIdx in BitIdxList
	 * @return 	The index of current BitIdx in BitIdxList
	 * @note 		This is done in relatively crude way, not sure if there is more elegant way of doing it
	 */
	template <BitListIdx BitIdx, BitListIdx... BitIdxList>
	static constexpr auto bitIdxOrder() noexcept {
		auto const bit_idx_list = std::array{BitIdxList...};
		return cstd::find(bit_idx_list.begin(), bit_idx_list.end(), BitIdx) - bit_idx_list.begin();
	}

	/**
	 * @brief			This function read register value if necessary
	 * @tparam  	BitIdx	Variadic template parameter that contains the positions of bits.
	 * @return		If reading register is necessary, then return the value of the register, otherwise return 0.
	 */
	template <BitListIdx... BitIdx>
	constexpr decltype(auto) readCurrentVal() const noexcept {
		constexpr auto need_to_read_current_val =
			((!CHECK_BIT_MOD<BitIdx>(BitMod::WrOnly) && !CHECK_BIT_MOD<BitIdx>(BitMod::RdSet)) || ...);

		if constexpr (need_to_read_current_val) {
			// return readReg();
			return readReg<BitIdx...>();
		} else {
			return 0;
		}
	}

 public:
	/**
	 *
	 */
	template <BitListIdx... Idx>
	[[nodiscard]] static constexpr auto isolateFrom() noexcept {
		return IsolateFrom_t<Idx...>{};
	}

	/**
	 * @brief		Construct Register by base peripheral address and offset
	 * @param   base   	Base peripheral address
	 * @param   offset 	Offset address
	 */
	explicit constexpr Register(std::uint32_t const base, std::uint32_t const offset) : m_base(base), m_offset(offset) {}

	/**
	 * @brief 	This function set single bit to 1
	 * @tparam	BitIdx	The bit to be set in the register
	 */
	template <BitListIdx BitIdx>
	constexpr void setBit() const noexcept {
		constexpr auto bit = GET_BIT<BitIdx>();

		static_assert(bit.LENGTH == 1);
		readReg<BitIdx>() |= bit.mask;
		// readReg() |= bit.mask;
	}

	/**
	 * @brief		This function set multiple bits to same value
	 * @tparam	BitIdx 		Variadic template parameter that contains the positions of bits.
	 * @tparam 	ValueType The type of the value to be set to. It must be the same as the representation (data type) of
	 * 										the bits to be set, see @ref Bit.
	 * @param 	t_param		Value to be written.
	 */
	template <BitListIdx... BitIdx, typename ValueType>
	constexpr void setBit(ValueType const& t_param) const noexcept {
		static_assert((IS_TYPE_AVAILABLE<BitIdx, ValueType>() && ...));
		static_assert((IS_BIT_WRITABLE<BitIdx>() && ...));

		auto const current_val = readCurrentVal<BitIdx...>();

		auto const mod_val		= (... | GET_BIT<BitIdx>()(t_param));
		auto const clear_mask = ~(... | GET_BIT<BitIdx>().mask);

		// readReg() = (current_val & clear_mask) | mod_val;
		readReg<BitIdx...>() = ((current_val & clear_mask) | mod_val);
	}

	/**
	 * @brief		This function set multiple bits to corresponding values
	 * @tparam	BitIdx			Variadic template parameter that contains the positions of bits.
	 * @tparam	ValueTypes	Variadic template parameter that contains the type to be set for each bit in BitIdx.
	 * @param 	t_param 		See @ref BitGroup, see @ref readBit. Since @ref readBit returns BitGroup, this
	 * 											function also takes BitGroup as paramter for simplicity.
	 */
	template <BitListIdx... BitIdx, typename... ValueTypes>
	constexpr void setBit(BitGroup<ValueTypes...> const& t_param) const noexcept {
		static_assert(sizeof...(BitIdx) == sizeof...(ValueTypes));
		static_assert((IS_TYPE_AVAILABLE<BitIdx, ValueTypes>() && ...));
		static_assert((IS_BIT_WRITABLE<BitIdx>() && ...));

		constexpr auto mod_val_for_each_bit = [](auto const& t_bit_idx, auto const& t_param) {
			constexpr auto bit		= GET_BIT<BitListIdx{t_bit_idx()}>();
			auto const val_to_mod = get<bitIdxOrder<BitListIdx{t_bit_idx()}, BitIdx...>()>(t_param);
			return bit(val_to_mod);
		};

		auto const current_val = readCurrentVal<BitIdx...>();

		auto const mod_val		= (... | mod_val_for_each_bit(size_c<to_underlying(BitIdx)>{}, t_param));
		auto const clear_mask = ~(... | GET_BIT<BitIdx>().mask);

		readReg<BitIdx...>() = ((current_val & clear_mask) | mod_val);
		// readReg() = ((current_val & clear_mask) | mod_val);
	}

	/**
	 * @brief		This function set multiple bits to corresponding values
	 * @tparam	ValueTypes	Variadic template parameter that contains the type to be set to for each bit in BitIdx.
	 * @param 	t_param			Input value to be set.
	 */
	template <BitListIdx... BitIdx, typename... ValueTypes>
	constexpr void setBit(ValueTypes const&... t_param) const noexcept {
		setBit<BitIdx...>(BitGroup{t_param...});
	}

	/**
	 * [setBit description]
	 * @param t_param [description]
	 *
	 * @note  this is used only if we need to set multiple bits at the same time, but this process needs to be
	 * 				thread safe, ref: https://github.com/kvasir-io/Kvasir/tree/master/Lib/Register.
	 *			  HOWEVER, I DON'T KNOW HOW THEY IMPLEMENT IT, @todo investigate furthur to understand how they implemented
	 */
	template <BitListIdx... BitIdx, typename... ValueTypes, BitListIdx... Avoid>
	constexpr void setBit(BitGroup<ValueTypes...> const& t_val, IsolateFrom_t<Avoid...> const& t_isolate) const noexcept {
		if constexpr (IS_SEPARABLE<Access::Byte, BitIdx...>(t_isolate) ||
									IS_SEPARABLE<Access::HalfWord, BitIdx...>(t_isolate)) {
		} else {
			// this would always be true, !true = false
			static_assert(!IS_SEPARABLE<Access::Word, BitIdx...>(t_isolate));
		}
	}

	/**
	 * [IS_SEPARABLE description]
	 * @param  t_a [description]
	 * @return     [description]
	 */
	template <Access access, BitListIdx... BitIdx, BitListIdx... IsolateIdx>
	static constexpr auto IS_SEPARABLE(IsolateFrom_t<IsolateIdx...> const& t_a) noexcept {
		constexpr auto mod_n		 = viewRegByAccessMode<BitIdx..., access>();
		constexpr auto isolate_n = viewRegByAccessMode<IsolateIdx..., access>();

		constexpr bool mod_and_isolated_in_same_byte = [=]() {
			for (int i = 0; i < mod_n.size(); ++i) {
				if (mod_n[i] && isolate_n[i]) {
					return true;
				}
			}

			return false;
		}();

		constexpr bool bits_in_same_access_unit = (cstd::array_count(mod_n, true) == 1);

		return bits_in_same_access_unit && !mod_and_isolated_in_same_byte;
	}

	/**
	 * @brief 	This function set the bit in atomic way
	 * @note 		This should check whether it is doable or not, according to bit banding address,
	 * 					not implemented yet
	 */
	template <BitListIdx BitIdx, typename ValueType>
	constexpr void atomicSetBit() const noexcept {
		static_assert(atomicity);
	}

	/**
	 * @brief		This function literally reads bits in the register
	 * @param  	ValWithPosType 		Overload tag, see @ref ValWithPosType
	 * @return	Bits value
	 *
	 * @note		Rethink, when do i really need this function, if really needed, maybe combine two function
	 * 					by returning std::pair<(value), std::tuple<...> (position)>
	 */
	template <BitListIdx... BitIdx>
	[[nodiscard]] constexpr auto readBit(ValWithPosType /*unused*/) const noexcept {
		static_assert((IS_BIT_READABLE<BitIdx>() && ...));
		constexpr auto mask = (GET_BIT<BitIdx>().mask | ...);
		return readReg() & mask;
	}

	/**
	 * @brief		This function reads bits and return BitGroup
	 * @param  	ValueOnlyType  	Overload tag, see @ref ValueOnlyType
	 * @return 	Bits value wrapped in BitGroup, see @ref BitGroup
	 *
	 * @note		using std::bitset?
	 */
	template <BitListIdx... BitIdx>
	[[nodiscard]] constexpr auto readBit(ValueOnlyType /*unused*/) const noexcept {
		static_assert((IS_BIT_READABLE<BitIdx>() && ...));

		auto const reg_val = readCurrentVal<BitIdx...>();
		return BitGroup{extractBitValue<BitIdx>(reg_val)...};
	}

	/**
	 * @brief		This function writes 0 to the register at bit at BitIdx
	 * @tparam 	BitIdx 	Position of the bit
	 */
	template <BitListIdx BitIdx>
	constexpr void clearBit() const noexcept {
		static_assert(!CHECK_BIT_MOD<BitIdx>(BitMod::RdClrWr1));

		constexpr auto bit = GET_BIT<BitIdx>();
		readReg() &= (~bit.mask);
	}

	/**
	 * @brief			This function returns the memory address of the register, it can be used for
	 * 						bit banding. (And is the reason why this function exists)
	 * @return		Memory address of the register
	 */
	[[nodiscard]] constexpr auto memAddr() const noexcept { return m_base + m_offset; }
};	// namespace cpp_stm32

template <typename BitList, typename BitIdx, Access IoOp>
using AtomicReg = Register<BitList, BitIdx, IoOp, true>;

/**
 * @def 		SETUP_REGISTER_INFO(Name, ...)
 * @brief		A helper macro to instantiate class (bit list) with class name @arg Name, and bits.
 */
#define SETUP_REGISTER_INFO(Name, ...)                                            \
	class Name {                                                                    \
		template <typename BitList, std::size_t Idx>                                  \
		friend constexpr auto cpp_stm32::get_bit() noexcept;                          \
                                                                                  \
	 private:                                                                       \
		static constexpr std::tuple BIT_LIST = make_bit_list_from_input(__VA_ARGS__); \
	};

/**
 * @brief		This function takes variadic input bit and turn it to tuple of bits
 * @param  	t_input		Input variadic bit
 * @return	tuple of bits
 */
static constexpr auto make_bit_list_from_input = [](auto const&... t_val) {
	constexpr auto check_input_and_make_tuple = [](auto const& t_input) {
		if constexpr (is_specialization<decltype(t_input), std::tuple>) {
			return t_input;
		} else {
			return std::tuple{t_input};
		}
	};

	return std::tuple_cat(check_input_and_make_tuple(t_val)...);
};

}	 // namespace cpp_stm32
