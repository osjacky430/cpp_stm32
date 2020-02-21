/**
 * @file  detail/tuple.hxx
 * @brief	self implementation of tuple
 *
 * @ref		https://stackoverflow.com/questions/4041447/how-is-stdtuple-implemented
 * @ref   https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/tuple
 */

/** Copyright (c) 2020 by osjacky430.
 * All Rights Reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstddef>
#include <tuple>
#include <utility>

namespace cpp_stm32::detail {

template <std::size_t i, typename...>
struct TupleImpl;

/**
 *
 * @param  t_tup [description]
 * @return       [description]
 *
 * @note  gcc implement tuple node by inheriting Head if Head is not final type (i.e., can't be inherited), if Head is
 * 				final type, then hold a instance of Head. In so doing, it can avoid instantiate class that holds large amount
 * 				of data (?)
 */
template <std::size_t i, typename Head>
struct TupleNode {
	Head val;

	/**
	 * @brief		Empty TupleImpl constructor
	 *
	 * @note		This reqiures Head to be default constructable
	 */
	constexpr TupleNode() noexcept : val{} {}

	/**
	 * @brief 	Construct TupleImpl with Head val
	 * @param  	t_head 	Head val
	 *
	 * @note  	This requires Head to be copy constructable
	 */
	explicit constexpr TupleNode(Head const& t_head) noexcept : val{t_head} {}

	static constexpr Head& HEAD_VAL(TupleNode& t_tup) noexcept { return t_tup.val; }

	static constexpr const Head& HEAD_VAL(TupleNode const& t_tup) noexcept { return t_tup.val; }
};

template <std::size_t i>
struct TupleImpl<i> {};

template <std::size_t i, typename Head, typename... Tail>
struct TupleImpl<i, Head, Tail...> : public TupleNode<i, Head>, public TupleImpl<i + 1, Tail...> {
	using TupleHead = TupleNode<i, Head>;
	using TupleTail = TupleImpl<i + 1, Tail...>;

	/**
	 * @brief    This function always returns the head of the tuple, this is done recursively, non-const version
	 * @param    t_tup   Input tuple
	 * @return   Head val
	 */
	static constexpr Head& HEAD_VAL(TupleImpl& t_tup) noexcept { return TupleHead::HEAD_VAL(t_tup); }

	/**
	 * @brief 	 This function always returns the head of the tuple, this is done recursively, const version
	 * @param    t_tup   Input tuple
	 * @return   Head val
	 */
	static constexpr Head const& HEAD_VAL(TupleImpl const& t_tup) noexcept { return TupleHead::HEAD_VAL(t_tup); }

	/**
	 * @brief    This function turn the input tuple to reference to base class TupleTail
	 * @param    t_tup   Input tuple
	 * @return   reference to TupleImpl base class, TupleTail, which consists of the rest of the element
	 */
	static constexpr TupleTail& TAIL_VAL(TupleImpl& t_tup) noexcept { return t_tup; }

	/**
	 * @brief    This function turn the input tuple to reference to base class TupleTail, const version
	 * @param    t_tup   Input tuple
	 * @return   reference to TupleImpl base class, TupleTail, which consists of the rest of the element
	 */
	static constexpr TupleTail const& TAIL_VAL(TupleImpl const& t_tup) noexcept { return t_tup; }

	/**
	 * @brief     Construct TupleImpl recursively
	 */
	constexpr TupleImpl() noexcept : TupleHead(), TupleTail() {}

	/**
	 * @brief  		Construct tuple with elements
	 * @param  		t_head 	Head value
	 * @param  		t_tail  The rest of value
	 */
	explicit constexpr TupleImpl(Head const& t_head, Tail const&... t_tail) noexcept
		: TupleHead{t_head}, TupleTail{t_tail...} {}

	/**
	 * @brief  	Construct tuple with another tuple
	 * @param  	t_tup  Another tuple
	 */
	template <typename... Elems>
	constexpr TupleImpl(TupleImpl<i, Elems...> const& t_tup) noexcept
		: TupleHead(TupleImpl<i, Elems...>::HEAD_VAL(t_tup)), TupleTail(TupleImpl<i, Elems...>::TAIL_VAL(t_tup)) {}

	/**
	 * @brief    Assignment operator, recursively assigning head val
	 * @param    t_tup   Other tuple
	 *
	 * @note     This requires all elements have well defined assignment operator
	 */
	template <typename... Elems>
	constexpr TupleImpl& operator=(TupleImpl<i, Elems...> const& t_tup) noexcept {
		HEAD_VAL(*this) = TupleImpl<i, Elems...>::HEAD_VAL(t_tup);
		TAIL_VAL(*this) = TupleImpl<i, Elems...>::TAIL_VAL(t_tup);
		return *this;
	}
};

/**
 * @brief  	Self implemented tuple due to some constexpr function is required but not yet constexpr in C++17
 * @tparam 	Elems Variadic template param
 *
 * @note 	instead of type aliasing, inheritance is better since for empty tuple, we dont need additional bracket, i.e.
 *
 * 				```
 * 				auto const tup = detail::Tuple{};  		// inheritnace
 * 				auto const tup = detail::Tuple<>{};	  // type alias, deduction guide can't help us either cause we are type
 * 																							// aliasing
 * 				```
 */
template <typename... Elems>
class Tuple : public TupleImpl<0, Elems...> {
	template <typename... Elems_>
	friend constexpr auto operator~(Tuple<Elems_...>&) noexcept;

 private:
	using Inherited = TupleImpl<0, Elems...>;

 public:
	constexpr Tuple(Tuple&&)			= default;
	constexpr Tuple(Tuple const&) = default;

	constexpr Tuple() noexcept : Inherited() {}

	/**
	 * @brief		Construct Tuple with elements
	 * @param  	t_elems Elements
	 *
	 * @note  	To avoid ambiguous when initializing empty tuple, we need SFINAE to separate this and default constructor
	 */
	template <bool = sizeof...(Elems) >= 1>
	explicit constexpr Tuple(Elems const&... t_elems) noexcept : Inherited(t_elems...) {}

	/**
	 * @brief  	Construct Tuple with std::tuple
	 * @param  	t_tup std::tuple
	 */
	explicit constexpr Tuple(std::tuple<Elems...> const& t_tup) noexcept {
		// @todo
	}

	/**
	 * @brief		Operator= for Tuple
	 * @param   t_tup 	the other Tuple
	 * @return  itself
	 */
	constexpr Tuple& operator=(Tuple const& t_tup) noexcept {
		Inherited::operator=(t_tup);
		return *this;
	}

	/**
	 * @brief  	Operator[] for Tuple, which takes integral constant as index
	 * @param   integral constant
	 * @return  const reference to element at index
	 */
	template <std::size_t Idx>
	[[nodiscard]] constexpr auto const& operator[](
		std::integral_constant<std::size_t, Idx> const& /*unused*/) const noexcept {
		return this->TupleImpl<Idx, Elems...>::HEAD_VAL(*this);
	}

	/**
	 * @brief  	Operator[] for Tuple, which takes integral constant as index
	 * @param   integral constant
	 * @return  reference to element at index
	 */
	template <std::size_t Idx>
	[[nodiscard]] constexpr auto& operator[](std::integral_constant<std::size_t, Idx>& /*unused*/) noexcept {
		return this->TupleImpl<Idx, Elems...>::HEAD_VAL(*this);
	}
};

// tuple get implementation, non const version
template <std::size_t Idx, typename Head, typename... Tails>
constexpr Head& get_impl(TupleImpl<Idx, Head, Tails...>& t_tup) noexcept {
	return TupleImpl<Idx, Head, Tails...>::HEAD_VAL(t_tup);
}

// tuple get implementation, const version
template <std::size_t Idx, typename Head, typename... Tails>
constexpr Head const& get_impl(TupleImpl<Idx, Head, Tails...> const& t_tup) noexcept {
	return TupleImpl<Idx, Head, Tails...>::HEAD_VAL(t_tup);
}

/**
 * @brief		This function gets the tuple element at index Idx const version
 * @tparam  Idx 	Index
 * @tparam 	Head  desire element type
 * @tparam  Tails the rest of the type
 *
 * @param   t_tup Tuple to get the value
 * @return  reference to the tuple element
 */
template <std::size_t Idx, typename Head, typename... Tails>
constexpr Head const& get(TupleImpl<Idx, Head, Tails...> const& t_tup) noexcept {
	return get_impl(t_tup);
}

/**
 * @brief		This function gets the tuple element at index Idx non-const version
 * @tparam  Idx 	Index
 * @tparam 	Head  desire element type
 * @tparam  Tails the rest of the type
 *
 * @param   t_tup Tuple to get the value
 * @return  reference to the tuple element
 */
template <std::size_t Idx, typename Head, typename... Tails>
constexpr Head& get(Tuple<Head, Tails...>& t_tup) noexcept {
	return get_impl(t_tup);
}

// tuple nand implementation
template <typename Tup, std::size_t... Idx>
[[nodiscard]] constexpr auto nand_impl(Tup const& t_tup, std::index_sequence<Idx...> const /* unused */) {
	return Tup{~get<Idx>(t_tup)...};
};

/**
 * @brief		Helper type to identify if all elements can apply NAND operator, this is verified by checking if it is
 *  				integral type.
 * @tparam  Elems 	Variadic template parameter
 *
 * @todo 		Extend it so that it can support custom class with nand operator overloading
 */
template <typename... Elems>
constexpr bool is_nand_operable = (std::is_integral_v<Elems> && ...);

/**
 * @brief  	Operator NAND for std::tuple
 * @tparam  Elems 	Variadic template parameter
 * @param		t_tup 	std::tuple
 *
 * @return  std::tuple with all element NANDed
 */
template <typename... Elems, typename = std::enable_if_t<is_nand_operable<Elems...>>>
[[nodiscard]] constexpr auto operator~(std::tuple<Elems...> const& t_tup) noexcept {
	return nand_impl<std::tuple<Elems...>>(t_tup, std::make_index_sequence<sizeof...(Elems)>{});
}

// Tuple to tuple implementation
template <typename... Elems, std::size_t... Idx>
[[nodiscard]] constexpr auto to_std_tup_impl(Tuple<Elems...> const& t_tup, std::index_sequence<Idx...> const) noexcept {
	return std::tuple{get<Idx>(t_tup)...};
}

/**
 * @brief 		This function transforms self implemented Tuple to std::tuple
 * @param  		t_tup	Tuple
 * @return    std::tuple
 */
template <typename... Elems>
[[nodiscard]] constexpr auto to_std_tuple(Tuple<Elems...> const& t_tup) noexcept {
	return to_std_tup_impl(t_tup, std::make_index_sequence<sizeof...(Elems)>{});
}

}	 // namespace cpp_stm32::detail

namespace std {
template <typename... Elems>
struct tuple_size<cpp_stm32::detail::Tuple<Elems...>> : std::integral_constant<std::size_t, sizeof...(Elems)> {};

template <std::size_t Idx, typename... Elems>
struct tuple_element<Idx, cpp_stm32::detail::Tuple<Elems...>> {
	using type = decltype(get<Idx>(std::declval<cpp_stm32::detail::Tuple<Elems...>>()));
};

}	 // namespace std
