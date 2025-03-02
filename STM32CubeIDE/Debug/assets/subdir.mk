################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../assets/startup_stm32h743xihx.s 

S_DEPS += \
./assets/startup_stm32h743xihx.d 

OBJS += \
./assets/startup_stm32h743xihx.o 


# Each subdirectory must supply rules for building sources it contributes
assets/%.o: ../assets/%.s assets/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"D:/APP/STM32CubeIDE_1.15.1/workspace/button/STM32CubeIDE/Application/User/Hardware" -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-assets

clean-assets:
	-$(RM) ./assets/startup_stm32h743xihx.d ./assets/startup_stm32h743xihx.o

.PHONY: clean-assets

