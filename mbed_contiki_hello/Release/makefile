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
-include Libraries/mbed-contiki-mbed-lpc1768/platform/mbed/slip-driver/subdir.mk
-include Libraries/mbed-contiki-mbed-lpc1768/platform/mbed/dev/subdir.mk
-include Libraries/mbed-contiki-mbed-lpc1768/platform/mbed/subdir.mk
-include Libraries/mbed-contiki-mbed-lpc1768/cpu/lpc1768/radio/subdir.mk
-include Libraries/mbed-contiki-mbed-lpc1768/cpu/lpc1768/dev/subdir.mk
-include Libraries/mbed-contiki-mbed-lpc1768/cpu/lpc1768/subdir.mk
-include Libraries/mbed-contiki-base/core/sys/subdir.mk
-include Libraries/mbed-contiki-base/core/net/rpl/subdir.mk
-include Libraries/mbed-contiki-base/core/net/rime/subdir.mk
-include Libraries/mbed-contiki-base/core/net/mac/sicslowmac/subdir.mk
-include Libraries/mbed-contiki-base/core/net/mac/contikimac/subdir.mk
-include Libraries/mbed-contiki-base/core/net/mac/subdir.mk
-include Libraries/mbed-contiki-base/core/net/ipv6/multicast/subdir.mk
-include Libraries/mbed-contiki-base/core/net/ipv6/subdir.mk
-include Libraries/mbed-contiki-base/core/net/ipv4/subdir.mk
-include Libraries/mbed-contiki-base/core/net/ip/subdir.mk
-include Libraries/mbed-contiki-base/core/net/subdir.mk
-include Libraries/mbed-contiki-base/core/lib/strncasecmp/subdir.mk
-include Libraries/mbed-contiki-base/core/lib/subdir.mk
-include Libraries/mbed-contiki-base/core/dev/subdir.mk
-include Libraries/mbed-contiki-base/core/cfs/subdir.mk
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
D:/mybed/mbed_contiki_hello/Release/mbed.ar \

ELF += \
mbed_contiki_hello.elf \

EEP += \
mbed_contiki_hello.eep \

FLASH_IMAGE += \
mbed_contiki_hello.hex \
mbed_contiki_hello.bin \

FLASH_IMAGE += \
mbed_contiki_hello.hex \
mbed_contiki_hello.bin \


# All Target
all: mbed_contiki_hello

# Tool invocations
mbed_contiki_hello: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-size" -A "D:/mybed/mbed_contiki_hello/Release/mbed_contiki_hello.elf"
	@echo 'Finished building target: $@'
	@echo ' '

D:/mybed/mbed_contiki_hello/Release/mbed.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-ar" -r "D:/mybed/mbed_contiki_hello/Release/mbed.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

mbed_contiki_hello.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-gcc" -mcpu=cortex-m3 -mthumb -Wl,--gc-sections --specs=nano.specs -u _printf_float -u _scanf_float  "-TD:/mbed CD/SMeshStudio_4.5.0/smeshcore/hardware/mbed/variants/xbed1.0_lpc1768_gcc_arm/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM/LPC1768.ld" -o "D:/mybed/mbed_contiki_hello/Release/mbed_contiki_hello.elf"   $(LINK_OBJ) $(AR)  -L"D:/mybed/mbed_contiki_hello/Release" -L"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/hardware/mbed/variants/xbed1.0_lpc1768_gcc_arm/cmsis/TARGET_NXP/TARGET_LPC176X/TOOLCHAIN_GCC_ARM" -lstdc++ -lsupc++ -lm -lc -lgcc -lnosys
	@echo 'Finished building: $@'
	@echo ' '

mbed_contiki_hello.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

mbed_contiki_hello.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-objcopy"  -Oihex "D:/mybed/mbed_contiki_hello/Release/mbed_contiki_hello.elf" "D:/mybed/mbed_contiki_hello/Release/mbed_contiki_hello.hex"
	@echo 'Finished building: $@'
	@echo ' '

mbed_contiki_hello.bin: $(EEP)
	@echo 'Create Flash image (bin format)'
	"D:/mbed CD/SMeshStudio_4.5.0/smeshcore/tools/gcc_arm/bin/arm-none-eabi-objcopy"  -Obinary "D:/mybed/mbed_contiki_hello/Release/mbed_contiki_hello.elf" "D:/mybed/mbed_contiki_hello/Release/mbed_contiki_hello.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(C_DEPS)$(AR)$(EEP)$(FLASH_IMAGE)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS) mbed_contiki_hello
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
