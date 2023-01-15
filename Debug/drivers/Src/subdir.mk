################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../drivers/Src/gpio.cpp \
../drivers/Src/systick.cpp \
../drivers/Src/usart.cpp 

OBJS += \
./drivers/Src/gpio.o \
./drivers/Src/systick.o \
./drivers/Src/usart.o 

CPP_DEPS += \
./drivers/Src/gpio.d \
./drivers/Src/systick.d \
./drivers/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su: ../drivers/Src/%.cpp drivers/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/gpio.d ./drivers/Src/gpio.o ./drivers/Src/gpio.su ./drivers/Src/systick.d ./drivers/Src/systick.o ./drivers/Src/systick.su ./drivers/Src/usart.d ./drivers/Src/usart.o ./drivers/Src/usart.su

.PHONY: clean-drivers-2f-Src

