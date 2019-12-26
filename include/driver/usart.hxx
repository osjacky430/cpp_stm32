/**
 * @Date:   2019-12-25T15:51:34+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: usart.hxx
 */

#pragma once

#include <tuple>
#include <utility>

#include "include/driver/gpio_base.hpp"
#include "include/driver/serial.hxx"
#include "include/hal/peripheral/rcc.hxx"
#include "include/hal/peripheral/usart.hxx"
#include "include/hal/utility.hxx"
#include "include/utility/constexpr_algo.hxx"

class UsartPinMap {
 private:
	using UsartAltFuncGroup = std::tuple<UsartNum, GpioAltFunc, RccPeriph>;

	static constexpr auto TX_PIN_MAP = std::array{
		std::pair{PinName::PA_2, UsartAltFuncGroup{UsartNum::Usart2, GpioAltFunc::AF7, RccPeriph::Usart2}},
	};

	static constexpr auto RX_PIN_MAP = std::array{
		std::pair{PinName::PA_3, UsartAltFuncGroup{UsartNum::Usart2, GpioAltFunc::AF7, RccPeriph::Usart2}},
	};

	static constexpr auto USART_PIN_MAP = std::tuple{TX_PIN_MAP, RX_PIN_MAP};

 public:
	enum class PinInfo { Tx, Rx };

	template <PinName Pin, PinInfo Idx>
	static constexpr auto getPinInfo() noexcept {
		constexpr auto PIN_MAP = std::get<to_underlying(Idx)>(USART_PIN_MAP);
		const auto iter_pos =
			cstd::find_if(PIN_MAP.begin(), PIN_MAP.end(), [](auto const& t_pair) { return (t_pair.first == Pin); });

		return iter_pos->second;
	};
};

template <PinName TX>
struct UsartTx {
	static constexpr auto TX_USART_NUM = std::get<0>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
	static constexpr auto TX_AF				 = std::get<1>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
	static constexpr auto TX_USART_RCC = std::get<2>(UsartPinMap::getPinInfo<TX, UsartPinMap::PinInfo::Tx>());
};

template <PinName TX>
static constexpr auto UsartTx_v = UsartTx<TX>{};

template <PinName RX>
struct UsartRx {
	static constexpr auto RX_USART_NUM = std::get<0>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
	static constexpr auto RX_AF				 = std::get<1>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
	static constexpr auto RX_USART_RCC = std::get<2>(UsartPinMap::getPinInfo<RX, UsartPinMap::PinInfo::Rx>());
};

template <PinName RX>
static constexpr auto UsartRx_v = UsartRx<RX>{};

template <PinName TX, PinName RX, PinName CTS = PinName::NC, PinName RTS = PinName::NC>
class Usart {
 private:
	static constexpr auto USART_PORT = UsartTx<TX>::TX_USART_NUM;

 public:
	explicit constexpr Usart(std::uint64_t const& t_baud) noexcept {}

	explicit constexpr Usart(UsartTx<TX> const& t_tx, UsartRx<RX> const& t_rx, std::uint64_t const t_baud) noexcept {
		static_assert(t_tx.TX_USART_NUM == t_rx.RX_USART_NUM);

		constexpr auto usart_af	 = t_tx.TX_AF;
		constexpr auto usart_rcc = t_tx.TX_USART_RCC;

		rcc_enable_periph_clk<usart_rcc>();
		//
		GpioUtil<TX, RX>::enableAllGpioClk();
		GpioUtil<TX, RX>::modeSetup(GpioMode::AltFunc, GpioPupd::None);
		GpioUtil<TX, RX>::alternateFuncSetup(usart_af);

		usart_set_baudrate<USART_PORT>(t_baud);
		usart_set_databit<USART_PORT>(DataBit::DataBit8);
		usart_set_parity<USART_PORT>(UsartParity::None);
		usart_set_stopbit<USART_PORT>(StopBit_v<UsartStopbit::Bit1>);

		usart_set_transfer_mode<USART_PORT>(UsartMode::TxRx);
		usart_set_hardware_flow_ctl<USART_PORT>(HardwareFlowControl::None);

		usart_enable<USART_PORT>();
	}

	constexpr auto operator<<(char const* val) const noexcept {
		for (char const* start = val; *start != '\0'; ++start) {
			usart_send_blocking<USART_PORT>(static_cast<std::uint8_t>(*start));
		}

		return *this;
	}

	template <typename T>
	constexpr auto operator<<(Serializable<T> const& t_serial) const noexcept {}
};
