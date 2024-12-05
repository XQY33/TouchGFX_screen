################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/Hardware/Wifi.c \
../Application/User/Hardware/WifiUser.c \
../Application/User/Hardware/ov5640.c \
../Application/User/Hardware/qspi_w25q64.c \
../Application/User/Hardware/sccb.c \
../Application/User/Hardware/sdram.c \
../Application/User/Hardware/touch_800x480.c \
../Application/User/Hardware/touch_iic.c 

C_DEPS += \
./Application/User/Hardware/Wifi.d \
./Application/User/Hardware/WifiUser.d \
./Application/User/Hardware/ov5640.d \
./Application/User/Hardware/qspi_w25q64.d \
./Application/User/Hardware/sccb.d \
./Application/User/Hardware/sdram.d \
./Application/User/Hardware/touch_800x480.d \
./Application/User/Hardware/touch_iic.d 

OBJS += \
./Application/User/Hardware/Wifi.o \
./Application/User/Hardware/WifiUser.o \
./Application/User/Hardware/ov5640.o \
./Application/User/Hardware/qspi_w25q64.o \
./Application/User/Hardware/sccb.o \
./Application/User/Hardware/sdram.o \
./Application/User/Hardware/touch_800x480.o \
./Application/User/Hardware/touch_iic.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/Hardware/%.o Application/User/Hardware/%.su Application/User/Hardware/%.cyclo: ../Application/User/Hardware/%.c Application/User/Hardware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I"D:/APP/STM32CubeIDE_1.15.1/workspace/button/STM32CubeIDE/Application/User/Hardware" -I"D:/APP/STM32CubeIDE_1.15.1/workspace/button/STM32CubeIDE/Application/User/Hardware" -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I"D:/APP/STM32CubeIDE_1.15.1/workspace/button/TouchGFX/gui/include/gui/model" -I"D:/APP/STM32CubeIDE_1.15.1/workspace/button/TouchGFX/gui/common" -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-Hardware

clean-Application-2f-User-2f-Hardware:
	-$(RM) ./Application/User/Hardware/Wifi.cyclo ./Application/User/Hardware/Wifi.d ./Application/User/Hardware/Wifi.o ./Application/User/Hardware/Wifi.su ./Application/User/Hardware/WifiUser.cyclo ./Application/User/Hardware/WifiUser.d ./Application/User/Hardware/WifiUser.o ./Application/User/Hardware/WifiUser.su ./Application/User/Hardware/ov5640.cyclo ./Application/User/Hardware/ov5640.d ./Application/User/Hardware/ov5640.o ./Application/User/Hardware/ov5640.su ./Application/User/Hardware/qspi_w25q64.cyclo ./Application/User/Hardware/qspi_w25q64.d ./Application/User/Hardware/qspi_w25q64.o ./Application/User/Hardware/qspi_w25q64.su ./Application/User/Hardware/sccb.cyclo ./Application/User/Hardware/sccb.d ./Application/User/Hardware/sccb.o ./Application/User/Hardware/sccb.su ./Application/User/Hardware/sdram.cyclo ./Application/User/Hardware/sdram.d ./Application/User/Hardware/sdram.o ./Application/User/Hardware/sdram.su ./Application/User/Hardware/touch_800x480.cyclo ./Application/User/Hardware/touch_800x480.d ./Application/User/Hardware/touch_800x480.o ./Application/User/Hardware/touch_800x480.su ./Application/User/Hardware/touch_iic.cyclo ./Application/User/Hardware/touch_iic.d ./Application/User/Hardware/touch_iic.o ./Application/User/Hardware/touch_iic.su

.PHONY: clean-Application-2f-User-2f-Hardware

