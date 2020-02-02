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

#include <array>
#include <cstddef>

namespace cpp_stm32 {

/**
 * [Serializable description]
 * @return [description]
 */
template <typename Derive>
class Serializable {
 protected:
	constexpr Serializable() noexcept {}

 public:
	constexpr auto serialize() const noexcept { return static_cast<Derive const*>(this)->serialization(); }
};

/**
 *
 */
template <bool W>
struct Waiting_t {};

template <bool W>
static constexpr auto Waiting = Waiting_t<W>{};

}	 // namespace cpp_stm32
