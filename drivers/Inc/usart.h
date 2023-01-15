/*
 * usart.h
 *
 *  Created on: Jan 15, 2023
 *      Author: rafaela
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include <stdint.h>

#define		__IO			volatile
#define APB1PERIPH_BASE		(PERIPH_BASE +  0x00000000U)
#define USART2_BASE			(APB1PERIPH_BASE + 0x4400U)


typedef struct
{
	__IO uint32_t SR;    /*USART Status Register*/
	__IO uint32_t DR;	 /*USART Data Register*/
	__IO uint32_t BRR;   /*USART Buad rate register*/
	__IO uint32_t CR1;   /*USART Control Register 1*/
	__IO uint32_t CR2;   /*USART Control Register 2*/
	__IO uint32_t CR3;   /*USART Control Register 3*/

}USART_TypeDef;

#define		USART2				((USART_TypeDef *)USART2_BASE)

typedef enum{
	RX_ONLY =0,
	TX_ONLY,
	RX_AND_TX
}UART_ComType;

typedef enum{
	_115200 = 0,
	_9600
}UART_BaudrateType;


class UARTComm{
	private:
		UART_ComType   			comtype;
		UART_BaudrateType 		baudrate;

	public:
		 UARTComm(UART_ComType _comtype, UART_BaudrateType _baudrate);
		 void LIB_UART_Write(int ch);
		 char LIB_UART_Read()const;
		 UART_ComType getCommType()const;
		 UART_BaudrateType getBaudrate()const;
};

#endif /* INC_USART_H_ */
