################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/chenillard.c" \
"../Sources/main.c" \
"../Sources/sci.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/chenillard.c \
../Sources/main.c \
../Sources/sci.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/chenillard_c.obj \
./Sources/main_c.obj \
./Sources/sci_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/chenillard_c.obj" \
"./Sources/main_c.obj" \
"./Sources/sci_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/chenillard_c.d \
./Sources/main_c.d \
./Sources/sci_c.d \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/chenillard_c.d" \
"./Sources/main_c.d" \
"./Sources/sci_c.d" \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/chenillard_c.obj \
./Sources/main_c.obj \
./Sources/sci_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Events.args" -ObjN="Sources/Events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/chenillard_c.obj: ../Sources/chenillard.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/chenillard.args" -ObjN="Sources/chenillard_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/sci_c.obj: ../Sources/sci.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/sci.args" -ObjN="Sources/sci_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


