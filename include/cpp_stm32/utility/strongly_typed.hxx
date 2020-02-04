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

/**
 * @namespace  cpp_stm32
 */
namespace cpp_stm32 {

/**
 * @class   StrongType
 * @brief   This class is used to create strong type for strong interface
 * @tparam  UnderlyingType  The underlying type of the strong type
 * @tparam  Tag             Tag to prevent those with same underlying type are used at the place they shouldn't
 */
template <typename UnderlyingType, typename Tag>
class StrongType {
 public:
	/**
	 * @brief  Construct StrongType with underlying value
	 * @param  t_val   The underlying value
	 */
	constexpr explicit StrongType(UnderlyingType const& t_val) noexcept : m_val(t_val) {}

	/**
	 * @brief  Getter function that returns the reference of its underlying value
	 * @return The reference of underlying value of the strong type
	 */
	[[nodiscard]] constexpr UnderlyingType& get() noexcept { return m_val; }

	/**
	 * @brief   Getter function that returns the constant reference of underlying value
	 * @return  The const reference of underlying value of the strong type
	 */
	[[nodiscard]] constexpr UnderlyingType const& get() const noexcept { return m_val; }

 private:
	UnderlyingType m_val;
};

using DeviceVolt_t = StrongType<float, struct Vdd_t>;
using BitPos_t		 = StrongType<std::uint32_t, struct BitPosition>;
using BitLength_t	 = StrongType<std::uint32_t, struct BitLength>;

using BaseAddr_t = StrongType<std::uint32_t, struct BaseAddress>;
using Offset_t	 = StrongType<std::uint16_t, struct Offset>;

using Priority_t = StrongType<std::size_t, struct Priority>;
using ResetVal_t = StrongType<std::uint32_t, struct ResetVal>;
}	 // namespace cpp_stm32
