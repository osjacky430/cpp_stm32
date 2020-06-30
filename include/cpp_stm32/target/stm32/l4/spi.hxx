#pragma once

#include <algorithm>
#include <array>

#include "cpp_stm32/target/stm32/l4/define/spi.hxx"
#include "cpp_stm32/target/stm32/l4/register/spi.hxx"
#include "sys_info.hpp"

namespace cpp_stm32::spi {

/**
 * @brief   This function check is SPI enabled
 * @tparam  SPI @reef spi::Port
 *
 * @return  true if enabled, false otherwise
 */
template <Port SPI>
constexpr auto is_enabled() noexcept {
	return reg::CR1<SPI>.template readBit<reg::CR1Field::SPE>(ValueOnly);
}

/**
 * @brief   This function disables SPI
 * @tparam  SPI @ref spi::Port
 */
template <Port SPI>
constexpr void disable() noexcept {
	reg::CR1<SPI>.template clearBit<reg::CR1Field::SPE>();
}

/**
 * @brief   This function enables SPI
 * @tparam  SPI @ref spi::Port
 */
template <Port SPI>
constexpr void enable() noexcept {
	reg::CR1<SPI>.template setBit<reg::CR1Field::SPE>();
}

/**
 * @brief   This function sets transfer mode of SPI
 * @tparam  SPI  @ref spi::Port
 * @tparam  TM   @ref spi::TransferMode
 */
template <Port SPI, TransferMode TM>
constexpr void set_transfer_mode() noexcept {
	if constexpr (TM == TransferMode::FullDuplex) {
		reg::CR1<SPI>.template clearBit<reg::CR1Field::BIDIMODE>();
	} else if constexpr (TM == TransferMode::TxHalfDuplex) {
		reg::CR1<SPI>.template setBit<reg::CR1Field::BIDIOE, reg::CR1Field::BIDIMODE>();
	} else if constexpr (TM == TransferMode::RxHalfDuplex) {
		reg::CR1<SPI>.template writeBit<reg::CR1Field::BIDIOE, reg::CR1Field::BIDIMODE>(std::uint8_t{0}, std::uint8_t{1});
	} else if constexpr (TM == TransferMode::TxSimplex) {
		reg::CR1<SPI>.template clearBit<reg::CR1Field::RXONLY>();
	} else if constexpr (TM == TransferMode::RxSimplex) {
		reg::CR1<SPI>.template writeBit<reg::CR1Field::BIDIMODE, reg::CR1Field::RXONLY>(std::uint8_t{0}, std::uint8_t{1});
	}
}

/**
 * @brief   This function enables SPI CRC calculation
 * @tparam  SPI @ref spi::Port
 */
template <Port SPI>
constexpr void enable_crc() noexcept {
	reg::CR1<SPI>.template setBit<reg::CR1Field::CRCEN>();
}

/**
 * @brief   This function disables SPI CRC calculation
 * @tparam  SPI @ref spi::Port
 */
template <Port SPI>
constexpr void disable_crc() noexcept {
	reg::CR1<SPI>.template clearBit<reg::CR1Field::CRCEN>();
}

/**
 * @brief   This function sets crc as next transfer target
 * @tparam  SPI @ref spi::Port
 */
template <Port SPI>
constexpr void set_crc_transfer_next() noexcept {
	reg::CR1<SPI>.template setBit<reg::CR1Field::CRCNEXT>();
}

/**
 * @brief   This function sets dff of SPI
 * @tparam  SPI     @ref spi::Port
 * @param   t_dff   @ref spi::CRCLen
 */
template <Port SPI>
constexpr void set_crc_length(CRCLen const t_crc_len) noexcept {
	reg::CR1<SPI>.template writeBit<reg::CR1Field::CRCLEN>(t_crc_len);
}

/**
 * @brief   This function sets datat size of SPI
 * @tparam  SPI     @ref spi::Port
 * @param   t_ds   @ref spi::DataSize
 */
template <Port SPI>
constexpr void set_data_size(DataSize const t_ds) noexcept {
	reg::CR2<SPI>.template writeBit<reg::CR2Field::DS>(t_ds);
}

/**
 * @brief   This function sets SPI slave select mode
 * @tparam  SPI   @ref spi::Port
 * @tparam  SS    @ref spi::SlaveSelectMode
 *
 * @note    Software slave select: the NSS pin input is replaced with the value from the SSI bit.
 */
template <Port SPI, SlaveSelectMode SS>
constexpr void set_slave_select_mode() noexcept {
	if constexpr (SS == SlaveSelectMode::Software) {
		reg::CR1<SPI>.template setBit<reg::CR1Field::SSM>();
	} else if constexpr (SS == SlaveSelectMode::InputHardware) {
		reg::CR1<SPI>.template clearBit<reg::CR1Field::SSM>();
		reg::CR2<SPI>.template clearBit<reg::CR2Field::SSOE>();
	} else if constexpr (SS == SlaveSelectMode::OutputHardware) {
		reg::CR1<SPI>.template clearBit<reg::CR1Field::SSM>();
		reg::CR2<SPI>.template setBit<reg::CR2Field::SSOE>();
	}
}

/**
 * @brief   This function enables SPI TX DMA
 * @tparam  SPI   @ref spi::Port
 */
template <Port SPI>
constexpr void enable_tx_dma() noexcept {
	reg::CR2<SPI>.template setBit<reg::CR2Field::TXDMAEN>();
}

/**
 * @brief   This function disables SPI TX DMA
 * @tparam  SPI   @ref spi::Port
 */
template <Port SPI>
constexpr void disable_tx_dma() noexcept {
	reg::CR2<SPI>.template clearBit<reg::CR2Field::TXDMAEN>();
}

/**
 * @brief   This function enables SPI RX DMA
 * @tparam  SPI   @ref spi::Port
 */
template <Port SPI>
constexpr void enable_rx_dma() noexcept {
	reg::CR2<SPI>.template setBit<reg::CR2Field::RXDMAEN>();
}

/**
 * @brief   This function disables SPI RX DMA
 * @tparam  SPI   @ref spi::Port
 */
template <Port SPI>
constexpr void disable_rx_dma() noexcept {
	reg::CR2<SPI>.template clearBit<reg::CR2Field::RXDMAEN>();
}

/**
 * @brief   This function sets the clock polarity and clock phase of SPI
 * @tparam  SPI     @ref spi::Port
 * @param   t_mode  @ref spi::Mode
 */
template <Port SPI>
constexpr void set_mode(Mode const t_mode) noexcept {
	std::uint8_t const idle_high					 = (t_mode == Mode::Mode2 || t_mode == Mode::Mode3);
	std::uint8_t const second_edge_capture = (t_mode == Mode::Mode1 || t_mode == Mode::Mode3);

	reg::CR1<SPI>.template writeBit<reg::CR1Field::CPHA, reg::CR1Field::CPOL>(second_edge_capture, idle_high);
}

/**
 * @brief   This function sets SPI to master mode
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void set_master_mode() noexcept {
	reg::CR1<SPI>.template setBit<reg::CR1Field::MSTR>();
}

/**
 * @brief   This funciton sets SPI to slave mode
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void set_slave_mode() noexcept {
	reg::CR1<SPI>.template clearBit<reg::CR1Field::MSTR>();
}

/**
 * @brief   This function lets SPI send MSB first
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void set_msb_first() noexcept {
	reg::CR1<SPI>.template clearBit<reg::CR1Field::LSBFIRST>();
}

/**
 * @brief   This function lets SPI send LSB first
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void set_lsb_first() noexcept {
	reg::CR1<SPI>.template setBit<reg::CR1Field::LSBFIRST>();
}

/**
 * @brief   This function sets SPI baudrate prescaler
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void set_baudrate_prescaler(Baudrate_t const t_spi_baud) noexcept {
	reg::CR1<SPI>.template writeBit<reg::CR1Field::BR>(t_spi_baud);
}

/**
 * @brief 	This function select closest SPI baudrate prescaler
 * @tparam 	SPI 	@ref spi::Port
 * @tparam 	HZ 		Desire frequency of SPI SCLK
 */
template <Port SPI, std::uint32_t HZ>
constexpr void set_baudrate(Frequency<HZ> const /**/) noexcept {
	constexpr auto& KV_PAIR = Baudrate_t::AVAIL_DIVISION_FACTOR;
	constexpr auto COMP			= [](auto const& t_val, auto const& t_pair) { return t_val < std::get<0>(t_pair); };
	constexpr auto division = []() {
		if constexpr (SPI == Port::SPI1) {
			return APB2_CLK_FREQ / HZ;
		} else if constexpr (SPI == Port::SPI2 || SPI == Port::SPI3) {
			return APB1_CLK_FREQ / HZ;
		}
	}();
	constexpr auto up_bound = std::get<0>(*detail::upper_bound(KV_PAIR.begin(), KV_PAIR.end(), division, COMP));

	// @todo: need to consider limit
	set_baudrate_prescaler<SPI>(Baudrate_t{uint32_c<up_bound>{}});
}

/**
 * @brief   This function sets nss output to high
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void nss_output_high() noexcept {
	reg::CR1<SPI>.template setBit<reg::CR1Field::SSI>();
}

/**
 * @brief   This function sets nss output to low
 * @tparam  SPI     @ref spi::Port
 */
template <Port SPI>
constexpr void nss_output_low() noexcept {
	reg::CR1<SPI>.template clearBit<reg::CR1Field::SSI>();
}

/**
 * @brief   This function set SPI frame format to motorola mode
 *
 * @note    Default mode is motorola mode
 */
template <Port SPI>
constexpr void set_frame_format_motorola() noexcept {
	reg::CR2<SPI>.template clearBit<reg::CR2Field::FRF>();
}

/**
 * @brief   This function set SPI frame format to TI mode
 *
 * @note    Default mode is motorola mode
 */
template <Port SPI>
constexpr void set_frame_format_ti() noexcept {
	reg::CR2<SPI>.template setBit<reg::CR2Field::FRF>();
}

/**
 * @brief   This function reads the status register of SPI
 * @return  std::tuple of required status
 */
template <Port SPI, Status... Flags>
[[nodiscard]] constexpr auto get_status() noexcept {
	return reg::SR<SPI>.template readBit<Flags...>(ValueOnly);
}

/**
 * @brief   This function returns tx buffer state
 * @return  std::tuple of tx flag, true if empty, false otherwise
 */
template <Port SPI>
constexpr auto get_tx_status = get_status<SPI, Status::TXE>;

/**
 * @brief  	This function wait until the status flag turns to desire value
 * @tparam 	SPI 	@ref spi::Port
 * @tparam 	Flag  @ref spi::Status
 *
 * @param		t_desire 	desire value of the status bit
 */
template <Port SPI, Status Flag>
constexpr auto wait_status(bool const t_desire) noexcept {
	while (std::get<0>(get_status<SPI, Flag>()) != t_desire) {
	}
}

/**
 * @brief   This function transmits 8 bit data to slave
 * @tparam  SPI   @ref spi::Port
 * @tparam  IterT iterator type
 */
template <Port SPI, typename IterT>
constexpr void send_blocking(IterT const t_begin, IterT const t_end) noexcept {
	constexpr auto WRITE_SIZE = []() {
		return FifoThreshold{sizeof(typename std::iterator_traits<IterT>::value_type) <= sizeof(std::uint8_t)};
	}();

	std::for_each(t_begin, t_end, [](auto const& t_v) {
		wait_status<SPI, Status::TXE>(true);
		reg::DR<SPI, WRITE_SIZE>.template writeBit<reg::DRField::DR>(static_cast<std::uint16_t>(t_v));
	});
}

/**
 * @brief     This function read N bytes of data from slave
 * @tparam    SPI   @ref spi::Port
 * @tparam    N     Number of data to receive
 */
template <Port SPI, typename DataType, std::uint8_t N>
constexpr auto receive_blocking(DataCount<DataType, N> const /*unused*/) noexcept {
	static_assert(std::is_same_v<DataType, std::uint8_t> || std::is_same_v<DataType, std::uint16_t>);
	constexpr auto WRITE_SIZE = []() { return FifoThreshold{sizeof(DataType) <= sizeof(std::uint8_t)}; }();

	std::array<std::uint16_t, N> ret_val{};
	std::generate(ret_val.begin(), ret_val.end(), []() {
		wait_status<SPI, Status::RXNE>(true);
		return reg::DR<SPI, WRITE_SIZE>.template readBit<reg::DRField::DR>(ValWithPos);
	});

	return ret_val;
}

/**
 * @brief   This function sends and receives data from slave
 * @param   t_bc    Byte to receive
 * @param   t_begin Begin of the tx buffer
 * @param   t_end   End of the tx buffer
 */
template <Port SPI, std::uint8_t N, typename IterT>
constexpr auto xfer_blocking(DataCount<typename std::iterator_traits<IterT>::value_type, N> const t_bc,
														 IterT const t_begin, IterT const t_end) {
	send_blocking<SPI>(t_begin, t_end);
	return receive_blocking<SPI, typename std::iterator_traits<IterT>::value_type>(t_bc);
}

/**
 * @brief   This function enables interrupt
 * @tparam  SPI   @ref spi::Port
 * @tparam  Flags @ref spi::InterruptFlag
 */
template <Port SPI, InterruptFlag... Flags>
constexpr void enable_irq() noexcept {
	constexpr auto to_cr2_field = [](InterruptFlag const t_flag) {
		switch (t_flag) {
			case InterruptFlag::TXEIE:
				return reg::CR2Field::TXEIE;
			case InterruptFlag::RXNEIE:
				return reg::CR2Field::RXNEIE;
			case InterruptFlag::ERRIE:
				return reg::CR2Field::ERRIE;
		}
	};

	reg::CR2<SPI>.template setBit<to_cr2_field(Flags)...>();
}

/**
 * @brief   This function disables interrupt
 * @tparam  SPI   @ref spi::Port
 * @tparam  Flags @ref spi::InterruptFlag
 */
template <Port SPI, InterruptFlag... Flags>
constexpr void disable_irq() noexcept {
	constexpr auto to_cr2_field = [](InterruptFlag const t_flag) {
		switch (t_flag) {
			case InterruptFlag::TXEIE:
				return reg::CR2Field::TXEIE;
			case InterruptFlag::RXNEIE:
				return reg::CR2Field::RXNEIE;
			case InterruptFlag::ERRIE:
				return reg::CR2Field::ERRIE;
		}
	};
	reg::CR2<SPI>.template clearBit<to_cr2_field(Flags)...>();
}

/**
 * @brief   This function sets the RX FIFO threshold
 * @tparam  SPI   @ref spi::Port
 * @param   t_thresh  @ref spi::FifoThreshold
 */
template <Port SPI>
constexpr void set_rx_fifo_threshold(FifoThreshold const t_thresh) noexcept {
	reg::CR2<SPI>.template writeBit<reg::CR2Field::FRXTH>(t_thresh);
}

/**
 * @brief   This function returns the RX FIFO level
 * @tparam  SPI   @ref spi::Port
 *
 * @return  @ref spi::FifoLevel
 */
template <Port SPI>
[[nodiscard]] constexpr auto get_rx_fifo_level() noexcept {
	return reg::SR<SPI>.template readBit<Status::FRLVL>(ValueOnly);
}

/**
 * @brief   This function returns the TX FIFO level
 * @tparam  SPI   @ref spi::Port
 *
 * @return  @ref spi::FifoLevel
 */
template <Port SPI>
[[nodiscard]] constexpr auto get_tx_fifo_level() noexcept {
	return reg::SR<SPI>.template readBit<Status::FTLVL>(ValueOnly);
}

/**
 *	@todo 	Not done yet
 */
template <Port SPI, TransferMode TM, SlaveSelectMode SSM, typename DataType, std::uint32_t Hz>
constexpr void init_master(Mode const t_mode, Frequency<Hz> t_baud) noexcept {
	using reg::CR1Field;

	constexpr std::uint8_t bidimode_val = (TM != TransferMode::RxSimplex && TM != TransferMode::TxSimplex);
	constexpr std::uint8_t bidioe_val		= (TM == TransferMode::TxHalfDuplex);
	constexpr std::uint8_t rxonly_val		= (TM == TransferMode::RxSimplex);

	constexpr std::uint8_t ssm_val	= SSM == SlaveSelectMode::Software;
	constexpr std::uint8_t ssoe_val = SSM == SlaveSelectMode::OutputHardware;

	std::uint8_t const idle_high					 = (t_mode == Mode::Mode2 || t_mode == Mode::Mode3);
	std::uint8_t const second_edge_capture = (t_mode == Mode::Mode1 || t_mode == Mode::Mode3);

	reg::CR1<SPI>.template writeBit<CR1Field::BIDIMODE, CR1Field::BIDIOE, CR1Field::RXONLY, CR1Field::SSM, CR1Field::CPHA, CR1Field::CPOL>(
		bidimode_val, bidioe_val, rxonly_val, ssm_val, second_edge_capture, idle_high);

	set_baudrate(t_baud);
}

}	// namespace cpp_stm32::spi
