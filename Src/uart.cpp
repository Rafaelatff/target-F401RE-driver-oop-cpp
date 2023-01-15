/*
 * uart.cpp
 *
 *  Created on: Jan 15, 2023
 *      Author: rafaela
 */

#include "../drivers/Inc/gpio.h"
#include "../drivers/Inc/usart.h"


int main(){
	UARTComm myComPort(TX_ONLY,_115200);
	while(1){
			myComPort.LIB_UART_Write('Y');
			myComPort.LIB_UART_Write('\r');
			myComPort.LIB_UART_Write('\n');
	}
}
