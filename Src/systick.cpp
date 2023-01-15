/*
 * systick.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: rafaela
 */

#include "../drivers/Inc/gpio.h"
#include "../drivers/Inc/systick.h"

int main (){
	SYSTICK delayTimer;

	GPIO_InitTypeDef myGPIO_InitStruct;
	myGPIO_InitStruct = __gpio_pin_params(GPIO_PIN_5, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);

	// Class object: Constructor function (PORTx,
	GPIO LD2(PORTA, GPIOA, &myGPIO_InitStruct);
	while(1){
		delayTimer.SysTick_delay(5); //5 seconds delay
		LD2.LIB_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	}
}



