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

/**
 * @def 	 SETUP_LOOKUP_TABLE_WITH_BOUND(ClassName, LowerBound, UpperBound)
 * @brief	 A helper macro to declare division factor helper class
 * @param  ClassName   	Class name
 * @param  LowerBound		Lower bound of division factor
 * @param  UpperBound		Upper bound of division factor
 */
#define SETUP_LOOKUP_TABLE_WITH_BOUND(ClassName, LowerBound, UpperBound)                             \
	struct ClassName {                                                                                 \
		std::uint32_t const m_value;                                                                     \
                                                                                                     \
		static constexpr auto MAX = UpperBound;                                                          \
		static constexpr auto MIN = LowerBound;                                                          \
                                                                                                     \
		template <std::uint32_t Val>                                                                     \
		constexpr ClassName(std::integral_constant<std::uint32_t, Val> const&) noexcept : m_value(Val) { \
			static_assert(LowerBound <= Val && Val <= UpperBound);                                         \
		}                                                                                                \
                                                                                                     \
		[[nodiscard]] constexpr auto operator()() const noexcept { return m_value; }                     \
		[[nodiscard]] constexpr auto get() const noexcept { return m_value; }                            \
	}

/**
 * @def 	 SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(ClassName, ...)
 * @param  ClassName 	Class name
 * @param  VARARGS    division factor - register value pair
 */
#define SETUP_LOOKUP_TABLE_WITH_KEY_VAL_PAIR(ClassName, ...)                                              \
	struct ClassName {                                                                                      \
		std::uint32_t const m_value;                                                                          \
		static constexpr std::array AVAIL_DIVISION_FACTOR{__VA_ARGS__};                                       \
                                                                                                          \
		template <std::uint32_t Val>                                                                          \
		static constexpr auto findDivisionFactor = []() {                                                     \
			constexpr auto iter_pos = cstd::find_if(AVAIL_DIVISION_FACTOR.begin(), AVAIL_DIVISION_FACTOR.end(), \
																							[](auto const& t_pair) { return t_pair.first == Val; });    \
			static_assert(iter_pos != AVAIL_DIVISION_FACTOR.end());                                             \
			return iter_pos->second;                                                                            \
		};                                                                                                    \
                                                                                                          \
		template <std::uint32_t Val>                                                                          \
		constexpr ClassName(std::integral_constant<std::uint32_t, Val> const&) noexcept                       \
			: m_value(findDivisionFactor<Val>()) {}                                                             \
                                                                                                          \
		[[nodiscard]] constexpr auto operator()() const noexcept { return m_value; }                          \
		[[nodiscard]] constexpr auto get() const noexcept { return m_value; }                                 \
	}
