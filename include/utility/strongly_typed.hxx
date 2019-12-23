/**
 * @Date:   2019-12-12T01:26:14+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: strongly_typed.hxx
 * @Last modified time: 2019-12-23T15:05:38+08:00
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
