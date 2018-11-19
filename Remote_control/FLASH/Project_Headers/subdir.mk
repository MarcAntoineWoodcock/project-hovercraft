################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Project_Headers/can.c" \

C_SRCS += \
../Project_Headers/can.c \

OBJS += \
./Project_Headers/can_c.obj \

OBJS_QUOTED += \
"./Project_Headers/can_c.obj" \

C_DEPS += \
./Project_Headers/can_c.d \

C_DEPS_QUOTED += \
"./Project_Headers/can_c.d" \

OBJS_OS_FORMAT += \
./Project_Headers/can_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Project_Headers/can_c.obj: ../Project_Headers/can.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Project_Headers/can.args" -ObjN="Project_Headers/can_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Project_Headers/%.d: ../Project_Headers/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


