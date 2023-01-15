/*
 * systick.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: rafaela
 */
#include "../drivers/Inc/systick.h"

SYSTICK::SYSTICK(){
	//empty
}

void SYSTICK::SysTick_delay(uint32_t sec){

	/*Configure SysTick*/
	// SysTick is 24-bit timer, so, value cannot pass 0xFFFFFF (dec: 16777215)
	// SysClk isn't configured, so SysClk is by default 16Mhz (16M cycles per second)
	// so, for a 1 second delay, just run 16M cycles
	SysTick->RVR =  16000000 -1; // load 16M value in Reload Value Register

	/*clear current value register*/
	// Clear the current value of the SysTick counter
	// After write here, also clears the SYST_CSR COUNTFLAG bit to 0
	SysTick->CVR = 0; // load 0 in Current Value Register

	/*Enable SysTick, no interrupt*/
	// bit field 0 ENABLE: 	0 = counter disable / 1 = counter enabled
	// bit field 1 TICKINT: 0 = counting down to zero does not assert the SysTick exception request
	// bit field 2 - CLKSOURCE: 0 = external clock / 1 = processor clock
	// bit field 16 - COUNTFLAG: Returns 1 if timer counted to 0 since last time this was read
	SysTick->CSR = 5; // load 0b101 in Control and Status Register

	for(uint32_t i=0;i<sec;i++){
	  while((SysTick->CSR &0x10000)== 0){} /*Wait until the COUNTFLAG is set*/
	}
	SysTick->CSR =0;  /*Stop the timer (En =0)*/
}

void SYSTICK::SysTick_delay_ms(uint32_t msec){

	/*Configure SysTick*/
	// SysTick is 24-bit timer, so, value cannot pass 0xFFFFFF (dec: 16777215)
	// SysClk isn't configured, so SysClk is by default 16Mhz (16M cycles per second)
	// so, for a 1 millisecond delay, just run 16M/1000 cycles
	SysTick->RVR =  16000 -1; // load 16k value in Reload Value Register

	/*clear current value register*/
	// Clear the current value of the SysTick counter
	// After write here, also clears the SYST_CSR COUNTFLAG bit to 0
	SysTick->CVR =0; // load 0 in Current Value Register

	/*Enable SysTick, no interrupt*/
	// bit field 0 ENABLE: 	0 = counter disable / 1 = counter enabled
	// bit field 1 TICKINT: 0 = counting down to zero does not assert the SysTick exception request
	// bit field 2 - CLKSOURCE: 0 = external clock / 1 = processor clock
	// bit field 16 - COUNTFLAG: Returns 1 if timer counted to 0 since last time this was read
	SysTick->CSR = 5; // load 0b101 in Control and Status Register

	for(uint32_t i=0;i<msec;i++){
		while((SysTick->CSR &0x10000)== 0){} /*Wait until the COUNTFLAG is set*/
	}
	SysTick->CSR =0;  /*Stop the timer (En =0)*/
}

