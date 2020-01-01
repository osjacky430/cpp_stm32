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

template <typename UnderlyingType, typename Tag>
class StrongType {
 public:
	constexpr explicit StrongType(UnderlyingType const& t_val) : m_val(t_val) {}

	constexpr UnderlyingType& get() { return m_val; }
	constexpr UnderlyingType const& get() const { return m_val; }

 private:
	UnderlyingType m_val;
};

using DeviceVolt_t = StrongType<float, struct Vdd_t>;
using BitPos_t		 = StrongType<std::uint32_t, struct BitPosition>;
using BitLength_t	 = StrongType<std::uint32_t, struct BitLength>;
using BaseAddr_t	 = StrongType<std::uint32_t, struct BaseAddress>;
using Offset_t		 = StrongType<std::uint16_t, struct Offset>;
