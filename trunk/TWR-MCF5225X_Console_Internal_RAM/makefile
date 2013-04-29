################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 16
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := "$(Gnu_Make_Install_DirEnv)/rm" -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Sources/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
proj5ms.elf \

EXECUTABLES_QUOTED += \
"proj5ms.elf" \

EXECUTABLES_OS_FORMAT += \
proj5ms.elf \

_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS += \
proj5ms.elf.s19 \

_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS_QUOTED += \
"proj5ms.elf.s19" \

_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS_OS_FORMAT += \
proj5ms.elf.s19 \


# All Target
call-burner := 0
ifneq ($(strip $(EXECUTABLES)),)
ifneq ($(strip $(BBL_SRCS_QUOTED)),)
call-burner := 1
endif
endif
ifeq ($(call-burner),1)
all: proj5ms.elf proj5ms.elf.s19
else
all: proj5ms.elf
endif

# Tool invocations
proj5ms.elf: $(OBJS) $(USER_OBJS) ../Project_Settings/Linker_Files/TWR-MCF5225X_Console_Internal_RAM.lcf
	@echo 'Building target: $@'
	@echo 'Executing target #17 $@'
	@echo 'Invoking: ColdFire Linker'
	"$(CF_ToolsDirEnv)/mwldmcf" @@"proj5ms.args" -o "proj5ms.elf"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

proj5ms.elf.s19: $(BBL_SRCS) $(EXECUTABLES)
	@echo 'Executing target #18 $@'
	@echo 'Invoking: Burner'
	"$(HC08ToolsEnv)/burner.exe"  -f="$<" -env"ABS_FILE=$(strip $(EXECUTABLES_OS_FORMAT))"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) "./*/*/*.obj" "./*/*.obj"  $(CPP_DEPS_QUOTED) $(CC_DEPS_QUOTED) $(_OUTPUTTYPE_NAME_BURNER_OUTPUT_OUTPUTS_QUOTED) $(CXX_DEPS_QUOTED) $(C_UPPER_DEPS_QUOTED) $(C++_DEPS_QUOTED) $(EXECUTABLES_QUOTED) "./*/*/*.d" "./*/*.d"  proj5ms.elf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
