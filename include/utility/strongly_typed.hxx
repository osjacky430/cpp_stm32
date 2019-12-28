/**
 * @Date:   2019-12-12T01:26:14+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: strongly_typed.hxx
 * @Last modified time: 2019-12-27T18:00:27+08:00
 */

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
