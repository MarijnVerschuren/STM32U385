################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../software/src/keypad.cpp \
../software/src/keyscan.cpp 

C_SRCS += \
../software/src/PAL.c 

C_DEPS += \
./software/src/PAL.d 

OBJS += \
./software/src/PAL.o \
./software/src/keypad.o \
./software/src/keyscan.o 

CPP_DEPS += \
./software/src/keypad.d \
./software/src/keyscan.d 


# Each subdirectory must supply rules for building sources it contributes
software/src/%.o software/src/%.su software/src/%.cyclo: ../software/src/%.c software/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUX_INCLUDE_USER_DEFINE_FILE -DUSE_HAL_DRIVER -DSTM32U385xx -c -I../USBX/App -I../USBX/Target -I../Core/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U3xx/Include -I../Middlewares/ST/usbx/common/core/inc -I../Middlewares/ST/usbx/ports/generic/inc -I../Middlewares/ST/usbx/common/usbx_stm32_device_controllers -I../Middlewares/ST/usbx/common/usbx_device_classes/inc -I../Drivers/CMSIS/Include -I"/home/marijn/Github/STM32U385/cube_project/Keypad_project/software/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
software/src/%.o software/src/%.su software/src/%.cyclo: ../software/src/%.cpp software/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUX_INCLUDE_USER_DEFINE_FILE -DUSE_HAL_DRIVER -DSTM32U385xx -c -I../USBX/App -I../USBX/Target -I../Core/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc -I../Drivers/STM32U3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U3xx/Include -I../Middlewares/ST/usbx/common/core/inc -I../Middlewares/ST/usbx/ports/generic/inc -I../Middlewares/ST/usbx/common/usbx_stm32_device_controllers -I../Middlewares/ST/usbx/common/usbx_device_classes/inc -I../Drivers/CMSIS/Include -I"/home/marijn/Github/STM32U385/cube_project/Keypad_project/software/inc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-software-2f-src

clean-software-2f-src:
	-$(RM) ./software/src/PAL.cyclo ./software/src/PAL.d ./software/src/PAL.o ./software/src/PAL.su ./software/src/keypad.cyclo ./software/src/keypad.d ./software/src/keypad.o ./software/src/keypad.su ./software/src/keyscan.cyclo ./software/src/keyscan.d ./software/src/keyscan.o ./software/src/keyscan.su

.PHONY: clean-software-2f-src

