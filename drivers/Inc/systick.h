/*
 * systick.h
 *
 *  Created on: Jan 15, 2023
 *      Author: rafaela
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include <stdint.h>

#define __IOM volatile /*Read/Write structure member permission*/
#define __OM volatile /* Write only structure member permission*/
#define __IM volatile /*Read only structure member permission*/

#define 		SCB_BASEADDR			    0xE000E008UL  /*System Control Base Address*/
#define 		SysTick_BASEADDR		  0xE000E010UL  /*SysTick Base Address*/

typedef struct{
__IOM uint32_t CSR;   	// Control and Status Register 	- 0x00 offset: 0xE000E010 + 0x0
__IOM uint32_t RVR;   	// Reload Value Register 		- 0x04 offset: 0xE000E010 + 0x4
__IOM uint32_t CVR;   	// Current Value Register		- 0x08 offset: 0xE000E010 + 0x8
__IM  uint32_t CALIB;	// Calibration Value Register	- 0x0C offset: 0xE000E010 + 0xC
}SysTick_TypeDef;

#define SysTick ((SysTick_TypeDef *)SysTick_BASEADDR) /*SysTick configuration structure*/

// APIs

class SYSTICK{
	public:
		SYSTICK(); // constructor
		void SysTick_delay(uint32_t sec);
		void SysTick_delay_ms(uint32_t msec);
};

#endif /* INC_SYSTICK_H_ */
