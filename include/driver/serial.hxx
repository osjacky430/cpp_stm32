/**
 * @Date:   2019-12-26T15:20:54+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: serial.hxx
 * @Last modified time: 2019-12-26T18:02:15+08:00
 */

#pragma once

#include <array>
#include <cstddef>

template <typename Derive>
class Serializable {
 protected:
	constexpr Serializable() noexcept {}

 public:
	constexpr auto serialize() const noexcept { return static_cast<Derive const*>(this)->serialization(); }
};
