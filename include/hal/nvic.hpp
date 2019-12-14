/**
 * @Date:   2019-11-20T17:17:14+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: nvic.hpp
 * @Last modified time: 2019-12-13T20:31:17+08:00
 */
#ifndef NVIC_HPP_
#define NVIC_HPP_

#include "include/hal/memory_map.hxx"
#include "include/hal/utility.hxx"

enum class IrqNum : std::uint8_t {
	WindowWatchDog = 0,
	ProgVoltDetector,
	NvicIrqTotal,
};

template <auto IrqGroup, auto IrqPrioGroup>
class NvicRegister {
	static constexpr auto NVIC_BASE				 = to_underlying(Scs::NvicBase);
	static constexpr auto NVIC_ISER_OFFSET = 0x000U + 0x04U * IrqGroup;
	static constexpr auto NVIC_ICER_OFFSET = 0x180U + 0x04U * IrqGroup;
	static constexpr auto NVIC_ISPR_OFFSET = 0x200U + 0x04U * IrqGroup;
	static constexpr auto NVIC_ICPR_OFFSET = 0x280U + 0x04U * IrqGroup;
	static constexpr auto NVIC_IABR_OFFSET = 0x300U + 0x04U * IrqGroup;
	static constexpr auto NVIC_IPR_OFFSET	 = 0x400U + 0x04U * IrqPrioGroup;
	static constexpr auto NVIC_STIR_OFFSET = 0xE00U;

 public:
	static constexpr auto ISER = []() noexcept -> decltype(auto) { return MMIO32(NVIC_BASE, NVIC_ISER_OFFSET); };
	static constexpr auto ICER = []() noexcept -> decltype(auto) { return MMIO32(NVIC_BASE, NVIC_ICER_OFFSET); };
	static constexpr auto ISPR = []() noexcept -> decltype(auto) { return MMIO32(NVIC_BASE, NVIC_ISPR_OFFSET); };
	static constexpr auto IABR = []() noexcept -> decltype(auto) { return MMIO32(NVIC_BASE, NVIC_IABR_OFFSET); };
	static constexpr auto STIR = []() noexcept -> decltype(auto) { return MMIO32(NVIC_BASE, NVIC_STIR_OFFSET); };
	static constexpr auto IPR	 = []() noexcept -> decltype(auto) { return MMIO8(NVIC_BASE, NVIC_IPR_OFFSET); };
};

template <IrqNum IRQn>
class Interrupt {
 private:
	static constexpr auto NVIC_IRQ_GROUP		= to_underlying(IRQn) / 32U;
	static constexpr auto NVIC_IRQ_IP_GROUP = to_underlying(IRQn) / 4U;
	static constexpr auto NVIC_IRQ_BIT_POS	= 1U << (to_underlying(IRQn) % 32U);

	static constexpr NvicRegister<NVIC_IRQ_GROUP, NVIC_IRQ_IP_GROUP> NVIC_REGS{};

 public:
	/**
	 * @brief This function enables the
	 */
	static constexpr void enable() noexcept { NVIC_REGS.ISER() = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief This function disables the interrupt
	 */
	static constexpr void disable() noexcept { NVIC_REGS.ICER() = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief  This function check whether the interrupt is pending
	 * @return true if current interrupt is pending, false otherwise
	 */
	static constexpr bool isPending() noexcept { return (NVIC_REGS.ISPR() & NVIC_IRQ_BIT_POS) == 1; }

	/**
	 * @brief	 This function set the interrupt to pending state
	 */
	static constexpr void setPending() noexcept { NVIC_REGS.ISPR() = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief  This function clears the pending state of the interrupt
	 */
	static constexpr void clearPending() noexcept { NVIC_REGS.ICPR() = NVIC_IRQ_BIT_POS; }

	/**
	 * @brief		This function checks whether the interrupt is active
	 * @return true if current interrupt is active, false otherwise
	 */
	static constexpr bool isActive() noexcept { return (NVIC_REGS.IABR() & NVIC_IRQ_BIT_POS) == 1; }

	/**
	 * @brief 	This function generate software interrupt
	 */
	static constexpr void generateSoftwareInterrupt() noexcept { NVIC_REGS.STIR() |= to_underlying(IRQn); }

	/**
	 * @brief			This function sets the priority of the interrupt
	 *
	 * @param 		t_priority 	Priority of the interrupt
	 */
	static constexpr void setPriority(const std::uint8_t t_priority) noexcept {
		if constexpr (to_underlying(IRQn) <= 0) {
			//
		} else {
			NVIC_REGS.IPR() = t_priority;
		}
	}
};

#endif	// NVIC_HPP_
