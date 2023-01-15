/*
 * main.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: rafaela
 */
#include "../drivers/Inc/gpio.h"
#include "../drivers/Inc/usart.h"

int main (){
	GPIO_InitTypeDef myGPIO_InitStruct;
	myGPIO_InitStruct = __gpio_pin_params(GPIO_PIN_5, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);

	// Class object: Constructor function (PORTx,
	GPIO LD2(PORTA, GPIOA, &myGPIO_InitStruct);

	// To read B1
	myGPIO_InitStruct = __gpio_pin_params(GPIO_PIN_13, GPIO_MODE_INPUT, GPIO_NOPULL);
	GPIO B1 (PORTC, GPIOC, &myGPIO_InitStruct);
	uint8_t btnState;

	while(1){

		// B1 is active low on NUCLEO board
		btnState = B1.LIB_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
		if (btnState == 0){
			for (int i; i<=900000;i++);
			LD2.LIB_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		}
	}
	return 0;
}

