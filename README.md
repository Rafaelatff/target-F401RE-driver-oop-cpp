# target-F401RE-driver-oop-cpp
One of my repositories for the 'Embedded Systems Object-Oriented Programming in C' course.

## project

This time, we created the projec using the tarfeted language C++.

![image](https://user-images.githubusercontent.com/58916022/212550988-0a19ac0b-7b9c-41fe-b874-932f8264581e.png)

The source files main.cpp and gpio.cpp were created, together with the gpio.h file with the following configuration:

![image](https://user-images.githubusercontent.com/58916022/212551225-96afecb5-f096-4334-8722-95210676663b.png)

# coding

We started by creating a class element with the name GPIO:

```cpp
class GPIO{
	private:
		GPIO_TypeDef 				GPIO_regsStruct;
		GPIO_InitTypeDef			GPIO_initStruct;
		PORT_NameType				GPIO_port;
	
	public:
		GPIO(PORT_NameType  GPIO_PortName, GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
		GPIO_PinState LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
		void LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
		void LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

		void __LIB_RCC_GPIOA_CLK_ENABLE()const;
		void __LIB_RCC_GPIOB_CLK_ENABLE()const;
		void __LIB_RCC_GPIOC_CLK_ENABLE()const;
		void __LIB_RCC_GPIOD_CLK_ENABLE()const;
		void __LIB_RCC_GPIOE_CLK_ENABLE()const;
		void __LIB_RCC_GPIOH_CLK_ENABLE()const;
};
```

For the class private types, we also created an enum type (*PORT_NameType*) to help us to identify (by using switch case) the PORT to be configured.

```cpp
typedef enum{
	PORTA = 1,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTH
}PORT_NameType;
```

For the public functions, we declared a function with same name of the class to be our constructor GPIO::GPIO.

# cpp code

In the source file, we started by coding the constructor function. We basically used the same code created for GPIO during the *C* classes but add the switch case function to call the functions that enable the port clock.

class name :: GPIO constructor function

```cpp
GPIO::GPIO(PORT_NameType GPIO_PortName, GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init){
	switch(GPIO_PortName){
		case PORTA:
			__LIB_RCC_GPIOA_CLK_ENABLE();
		break;
		case PORTB:
			__LIB_RCC_GPIOB_CLK_ENABLE();
		break;
		case PORTC:
			__LIB_RCC_GPIOC_CLK_ENABLE();
		break;
		case PORTD:
			__LIB_RCC_GPIOD_CLK_ENABLE();
		break;
		case PORTE:
			__LIB_RCC_GPIOE_CLK_ENABLE();
		break;
		case PORTH:
			__LIB_RCC_GPIOH_CLK_ENABLE();
		break;
		default:
		break;
	}

	uint32_t position;
	uint32_t temp =  0x0U;
	uint32_t ioposition = 0x00U;
	uint32_t iocurrent =  0x00U;

	for(position =0U;position<GPIO_NUMBER;position++){
		ioposition = 0x01U << position;
		iocurrent =  (uint32_t)(GPIO_Init->Pin)&ioposition;
		if(iocurrent == ioposition){
			temp  =  GPIOx->MODER;
			temp &=~(GPIO_MODER_MODE0 <<(position * 2U));
			temp |=(GPIO_Init->Mode & GPIO_MODE) <<(position *2U);
			GPIOx->MODER =  temp;

			temp  =  GPIOx->PUPDR;
			temp &=~(GPIO_PUPDR_PUPDR0 <<(position * 2U));
			temp |=((GPIO_Init->Pull) << (position *2U));
			GPIOx->PUPDR = temp;
		}
	}
}
```

We just copy the LIB_GPIO_ReadPin function from our *C* code file, but added the class name in front of the function.

```cpp
GPIO_PinState GPIO::LIB_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	GPIO_PinState bitstatus;
	if((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET){
		bitstatus = GPIO_PIN_SET;
	} else{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}
```

Same for the LIB_GPIO_WritePin and LIB_GPIO_TogglePin functions:

```cpp
void GPIO::LIB_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState){
	if(PinState != GPIO_PIN_RESET){
		GPIOx->BSRR  =GPIO_Pin;
	} else{
		GPIOx->BSRR = (uint32_t)GPIO_Pin <<16;
	}
}

void GPIO::LIB_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	 GPIOx->ODR ^= GPIO_Pin;
}
```

For the clock enable functions, we changed from:
```c
void __LIB_RCC_GPIOA_CLK_ENABLE(void){ RCC->AHB1ENR |= GPIOA_EN;}
```
To:
```cpp
void GPIO::__LIB_RCC_GPIOA_CLK_ENABLE()const{ RCC->AHB1ENR |= GPIOA_EN;}
```
