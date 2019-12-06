/**
 * @Date:   2019-12-06T12:56:45+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hpp
 * @Last modified time: 2019-12-06T12:57:04+08:00
 */

#ifndef DRIVER_UTILITY_HPP_
#define DRIVER_UTILITY_HPP_

template <std::size_t idx>
using ConstIndexType = std::integral_constant<std::size_t, idx>;

#endif
