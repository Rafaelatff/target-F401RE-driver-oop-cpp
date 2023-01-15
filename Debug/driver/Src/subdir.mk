################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../driver/Src/gpio.cpp 

OBJS += \
./driver/Src/gpio.o 

CPP_DEPS += \
./driver/Src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/%.o driver/Src/%.su: ../driver/Src/%.cpp driver/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"D:/Estudos/Udemy/My_workspace/target/target-F401RE-driver-oop-cpp/driver/Inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-Src

clean-driver-2f-Src:
	-$(RM) ./driver/Src/gpio.d ./driver/Src/gpio.o ./driver/Src/gpio.su

.PHONY: clean-driver-2f-Src

