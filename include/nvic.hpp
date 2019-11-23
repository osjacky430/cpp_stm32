/**
 * @Date:   2019-11-20T17:17:14+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: nvic.hpp
 * @Last modified time: 2019-11-23T23:51:59+08:00
 */
#ifndef NVIC_HPP_
#define NVIC_HPP_

#include "memory_map.hpp"
#include "utility.hpp"

enum class IrqNum : std::uint8_t {
	WindowWatchDog = 0,
	ProgVoltDetector,
	NvicIrqTotal,
};

template <IrqNum IRQn>
class Interrupt {
 private:
	static constexpr auto NVIC_IRQ_GROUP = to_underlying(IRQn) / 32U;
	static constexpr auto NVIC_IRQ_IP_GROUP = to_underlying(IRQn) / 4U;
	static constexpr auto NVIC_IRQ_BIT_POS = 1U << (to_underlying(IRQn) % 32U);

	static constexpr auto NVIC_BASE = to_underlying(Scs::NvicBase);
	static constexpr auto NVIC_ISER_OFFSET = 0x000U + 0x04U * NVIC_IRQ_GROUP;
	static constexpr auto NVIC_ICER_OFFSET = 0x180U + 0x04U * NVIC_IRQ_GROUP;
	static constexpr auto NVIC_ISPR_OFFSET = 0x200U + 0x04U * NVIC_IRQ_GROUP;
	static constexpr auto NVIC_ICPR_OFFSET = 0x280U + 0x04U * NVIC_IRQ_GROUP;
	static constexpr auto NVIC_IABR_OFFSET = 0x300U + 0x04U * NVIC_IRQ_GROUP;
	static constexpr auto NVIC_IPR_OFFSET = 0x400U + 0x04U * NVIC_IRQ_IP_GROUP;
	static constexpr auto NVIC_STIR_OFFSET = 0xE00U;

 public:
	/**
	 * @brief This function enables the
	 */
	static constexpr void enable() noexcept { MMIO32(NVIC_BASE, NVIC_ISER_OFFSET) = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief This function disables the interrupt
	 */
	static constexpr void disable() noexcept { MMIO32(NVIC_BASE, NVIC_ICER_OFFSET) = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief  This function check whether the interrupt is pending
	 * @return true if current interrupt is pending, false otherwise
	 */
	static constexpr bool isPending() noexcept { return (MMIO32(NVIC_BASE, NVIC_ISPR_OFFSET) & NVIC_IRQ_BIT_POS) == 1; }

	/**
	 * @brief	 This function set the interrupt to pending state
	 */
	static constexpr void setPending() noexcept { MMIO32(NVIC_BASE, NVIC_ISPR_OFFSET) = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief  This function clears the pending state of the interrupt
	 */
	static constexpr void clearPending() noexcept { MMIO32(NVIC_BASE, NVIC_ICPR_OFFSET) = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief		This function checks whether the interrupt is active
	 * @return true if current interrupt is active, false otherwise
	 */
	static constexpr bool isActive() noexcept { return (MMIO32(NVIC_BASE, NVIC_IABR_OFFSET) & NVIC_IRQ_BIT_POS) == 1; }

	/**
	 * @brief 	This function generate software interrupt
	 */
	static constexpr void generateSoftwareInterrupt() noexcept {
		MMIO32(NVIC_BASE, NVIC_STIR_OFFSET) |= to_underlying(IRQn);
	}

	/**
	 * @brief			This function sets the priority of the interrupt
	 *
	 * @param 		t_priority 	Priority of the interrupt
	 */
	static constexpr void setPriority(const std::uint8_t t_priority) noexcept {
		if constexpr (to_underlying(IRQn) <= 0) {
			//
		} else {
			MMIO8(NVIC_BASE, NVIC_IPR_OFFSET) = t_priority;
		}
	}
};

#endif	// NVIC_HPP_
