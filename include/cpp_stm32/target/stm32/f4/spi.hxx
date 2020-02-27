/**
 * @file  stm32/f4/spi.hxx
 * @brief	SPI setup API for stm32f4
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

#include <algorithm>
#include <array>
#include <cstdint>
#include <type_traits>

#include "cpp_stm32/target/stm32/f4/define/spi.hxx"
#include "cpp_stm32/target/stm32/f4/register/spi.hxx"

namespace cpp_stm32::spi {

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
 * @brief   This function sets sdata as next transfer target
 * @tparam  SPI @ref spi::Port
 */
template <Port SPI>
constexpr void set_data_transfer_next() noexcept {
	reg::CR1<SPI>.template clearBit<reg::CR1Field::CRCNEXT>();
}

/**
 * @brief   This function sets dff of SPI
 * @tparam  SPI     @ref spi::Port
 * @param   t_dff   @ref spi::DataFrameFormat
 */
template <Port SPI>
constexpr void set_data_frame_format(DataFrameFormat const t_dff) noexcept {
	reg::CR1<SPI>.template writeBit<reg::CR1Field::DFF>(t_dff);
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
	std::uint8_t idle_high					 = (t_mode == Mode::Mode2 || t_mode == Mode::Mode3);
	std::uint8_t second_edge_capture = (t_mode == Mode::Mode1 || t_mode == Mode::Mode3);

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
constexpr void set_baudrate_prescaler(SpiBaurdrate_t const t_spi_baud) noexcept {
	reg::CR1<SPI>.template writeBit<reg::CR1Field::BR>(t_spi_baud);
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
 * @tparam  IterT iterator type
 */
template <Port SPI, typename IterT>
constexpr void send_blocking(IterT const t_begin, IterT const t_end) noexcept {
	std::for_each(t_begin, t_end, [](auto const& t_v) {
		wait_status<SPI, Status::TXE>(true);
		reg::DR<SPI>.template writeBit<reg::DRField::DR>(static_cast<std::uint16_t>(t_v));
	});
}

/**
 * @brief     This function read N bytes of data from slave
 * @tparam    SPI   @ref spi::Port
 * @tparam    N     Number of data to receive
 */
template <Port SPI, std::size_t N>
constexpr std::array<std::uint16_t, N> read_blocking(ByteCount<N> const) noexcept {
	std::array<std::uint16_t, N> ret_val{};
	std::generate(ret_val.begin(), ret_val.end(), []() {
		wait_status<SPI, Status::RXNE>();
		return std::get<0>(reg::DR<SPI>.template readBit<reg::DRField::DR>());
	});

	return ret_val;
}

/**
 * @brief   This function send and receive data from slave
 * @param   t_bc    Byte to receive
 * @param   t_begin Begin of the tx buffer
 * @param   t_end   End of the tx buffer
 */
template <Port SPI, std::size_t N, typename IterT>
constexpr std::array<std::uint16_t, N> xfer_blocking(ByteCount<N> const t_bc, IterT const t_begin, IterT const t_end) {
	send_blocking<SPI>(t_begin, t_end);
	return read_blocking<SPI>(t_bc);
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

}	 // namespace cpp_stm32::spi
