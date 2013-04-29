################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/TWR-MCF5225X_sysinit.c" \
"../Sources/console_io_cf.c" \
"../Sources/dtim.c" \
"../Sources/exceptions.c" \
"../Sources/gpt.c" \
"../Sources/i2c.c" \
"../Sources/itrc.c" \
"../Sources/ledm.c" \
"../Sources/main.c" \
"../Sources/nunchuck.c" \
"../Sources/pacman.c" \
"../Sources/pit.c" \
"../Sources/pwm.c" \
"../Sources/qspi.c" \
"../Sources/uart_support.c" \

C_SRCS += \
../Sources/TWR-MCF5225X_sysinit.c \
../Sources/console_io_cf.c \
../Sources/dtim.c \
../Sources/exceptions.c \
../Sources/gpt.c \
../Sources/i2c.c \
../Sources/itrc.c \
../Sources/ledm.c \
../Sources/main.c \
../Sources/nunchuck.c \
../Sources/pacman.c \
../Sources/pit.c \
../Sources/pwm.c \
../Sources/qspi.c \
../Sources/uart_support.c \

OBJS += \
./Sources/TWR-MCF5225X_sysinit_c.obj \
./Sources/console_io_cf_c.obj \
./Sources/dtim_c.obj \
./Sources/exceptions_c.obj \
./Sources/gpt_c.obj \
./Sources/i2c_c.obj \
./Sources/itrc_c.obj \
./Sources/ledm_c.obj \
./Sources/main_c.obj \
./Sources/nunchuck_c.obj \
./Sources/pacman_c.obj \
./Sources/pit_c.obj \
./Sources/pwm_c.obj \
./Sources/qspi_c.obj \
./Sources/uart_support_c.obj \

OBJS_QUOTED += \
"./Sources/TWR-MCF5225X_sysinit_c.obj" \
"./Sources/console_io_cf_c.obj" \
"./Sources/dtim_c.obj" \
"./Sources/exceptions_c.obj" \
"./Sources/gpt_c.obj" \
"./Sources/i2c_c.obj" \
"./Sources/itrc_c.obj" \
"./Sources/ledm_c.obj" \
"./Sources/main_c.obj" \
"./Sources/nunchuck_c.obj" \
"./Sources/pacman_c.obj" \
"./Sources/pit_c.obj" \
"./Sources/pwm_c.obj" \
"./Sources/qspi_c.obj" \
"./Sources/uart_support_c.obj" \

C_DEPS += \
./Sources/TWR-MCF5225X_sysinit_c.d \
./Sources/console_io_cf_c.d \
./Sources/dtim_c.d \
./Sources/exceptions_c.d \
./Sources/gpt_c.d \
./Sources/i2c_c.d \
./Sources/itrc_c.d \
./Sources/ledm_c.d \
./Sources/main_c.d \
./Sources/nunchuck_c.d \
./Sources/pacman_c.d \
./Sources/pit_c.d \
./Sources/pwm_c.d \
./Sources/qspi_c.d \
./Sources/uart_support_c.d \

OBJS_OS_FORMAT += \
./Sources/TWR-MCF5225X_sysinit_c.obj \
./Sources/console_io_cf_c.obj \
./Sources/dtim_c.obj \
./Sources/exceptions_c.obj \
./Sources/gpt_c.obj \
./Sources/i2c_c.obj \
./Sources/itrc_c.obj \
./Sources/ledm_c.obj \
./Sources/main_c.obj \
./Sources/nunchuck_c.obj \
./Sources/pacman_c.obj \
./Sources/pit_c.obj \
./Sources/pwm_c.obj \
./Sources/qspi_c.obj \
./Sources/uart_support_c.obj \

C_DEPS_QUOTED += \
"./Sources/TWR-MCF5225X_sysinit_c.d" \
"./Sources/console_io_cf_c.d" \
"./Sources/dtim_c.d" \
"./Sources/exceptions_c.d" \
"./Sources/gpt_c.d" \
"./Sources/i2c_c.d" \
"./Sources/itrc_c.d" \
"./Sources/ledm_c.d" \
"./Sources/main_c.d" \
"./Sources/nunchuck_c.d" \
"./Sources/pacman_c.d" \
"./Sources/pit_c.d" \
"./Sources/pwm_c.d" \
"./Sources/qspi_c.d" \
"./Sources/uart_support_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/TWR-MCF5225X_sysinit_c.obj: ../Sources/TWR-MCF5225X_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/TWR-MCF5225X_sysinit.args" -o "Sources/TWR-MCF5225X_sysinit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/console_io_cf_c.obj: ../Sources/console_io_cf.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/console_io_cf.args" -o "Sources/console_io_cf_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/dtim_c.obj: ../Sources/dtim.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/dtim.args" -o "Sources/dtim_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/exceptions_c.obj: ../Sources/exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/exceptions.args" -o "Sources/exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/gpt_c.obj: ../Sources/gpt.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/gpt.args" -o "Sources/gpt_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/i2c_c.obj: ../Sources/i2c.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/i2c.args" -o "Sources/i2c_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/itrc_c.obj: ../Sources/itrc.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/itrc.args" -o "Sources/itrc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ledm_c.obj: ../Sources/ledm.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/ledm.args" -o "Sources/ledm_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/nunchuck_c.obj: ../Sources/nunchuck.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/nunchuck.args" -o "Sources/nunchuck_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/pacman_c.obj: ../Sources/pacman.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/pacman.args" -o "Sources/pacman_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/pit_c.obj: ../Sources/pit.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/pit.args" -o "Sources/pit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/pwm_c.obj: ../Sources/pwm.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/pwm.args" -o "Sources/pwm_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/qspi_c.obj: ../Sources/qspi.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/qspi.args" -o "Sources/qspi_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart_support_c.obj: ../Sources/uart_support.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/uart_support.args" -o "Sources/uart_support_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


