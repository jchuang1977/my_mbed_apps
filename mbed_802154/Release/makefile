################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include mBed/variant/hal/TARGET_NXP/TARGET_LPC176X/subdir.mk
-include mBed/variant/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM/subdir.mk
-include mBed/variant/cmsis/TARGET_NXP/TARGET_LPC176X/subdir.mk
-include mBed/core/common/subdir.mk
-include Libraries/mbed-MxRadioRF2xx/uracolib/subdir.mk
-include Libraries/mbed-MxRadioRF2xx/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
D:/mybed/mbed_802154/Release/mbed.ar \

ELF += \
mbed_802154.elf \

EEP += \
mbed_802154.eep \

FLASH_IMAGE += \
mbed_802154.hex \
mbed_802154.bin \

FLASH_IMAGE += \
mbed_802154.hex \
mbed_802154.bin \


# All Target
all: mbed_802154

# Tool invocations
mbed_802154: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-size" -A "D:/mybed/mbed_802154/Release/mbed_802154.elf"
	@echo 'Finished building target: $@'
	@echo ' '

D:/mybed/mbed_802154/Release/mbed.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-ar" -r "D:/mybed/mbed_802154/Release/mbed.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

mbed_802154.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-gcc" -mcpu=cortex-m3 -mthumb -Wl,--gc-sections --specs=nano.specs -u _printf_float -u _scanf_float  "-TD:/mbed CD/SMeshStudio_4.5.0/smeshcore/hardware/mbed/variants/xbed1.0_lpc1768_gcc_arm/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM/LPC1768.ld" -o "D:/mybed/mbed_802154/Release/mbed_802154.elf"   $(LINK_OBJ) $(AR)  -L"D:/mybed/mbed_802154/Release" -L"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/hardware/mbed/variants/xbed1.0_lpc1768_gcc_arm/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM" -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys
	@echo 'Finished building: $@'
	@echo ' '

mbed_802154.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

mbed_802154.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-objcopy"  -Oihex "D:/mybed/mbed_802154/Release/mbed_802154.elf" "D:/mybed/mbed_802154/Release/mbed_802154.hex"
	@echo 'Finished building: $@'
	@echo ' '

mbed_802154.bin: $(EEP)
	@echo 'Create Flash image (bin format)'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-objcopy"  -Obinary "D:/mybed/mbed_802154/Release/mbed_802154.elf" "D:/mybed/mbed_802154/Release/mbed_802154.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) mbed_802154
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
