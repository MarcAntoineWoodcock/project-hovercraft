################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/BATT.c" \
"../Sources/DEMARRAGE.c" \
"../Sources/Events.c" \
"../Sources/LED_BATT.c" \
"../Sources/PWM.c" \
"../Sources/main.c" \

C_UPPER_SRCS += \
../Sources/RECEPTION.C \

C_UPPER_SRCS_QUOTED += \
"../Sources/RECEPTION.C" \

C_SRCS += \
../Sources/BATT.c \
../Sources/DEMARRAGE.c \
../Sources/Events.c \
../Sources/LED_BATT.c \
../Sources/PWM.c \
../Sources/main.c \

OBJS += \
./Sources/BATT_c.obj \
./Sources/DEMARRAGE_c.obj \
./Sources/Events_c.obj \
./Sources/LED_BATT_c.obj \
./Sources/PWM_c.obj \
./Sources/RECEPTION_C.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/BATT_c.obj" \
"./Sources/DEMARRAGE_c.obj" \
"./Sources/Events_c.obj" \
"./Sources/LED_BATT_c.obj" \
"./Sources/PWM_c.obj" \
"./Sources/RECEPTION_C.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/BATT_c.d \
./Sources/DEMARRAGE_c.d \
./Sources/Events_c.d \
./Sources/LED_BATT_c.d \
./Sources/PWM_c.d \
./Sources/main_c.d \

C_UPPER_DEPS_QUOTED += \
"./Sources/RECEPTION_C.d" \

C_UPPER_DEPS += \
./Sources/RECEPTION_C.d \

C_DEPS_QUOTED += \
"./Sources/BATT_c.d" \
"./Sources/DEMARRAGE_c.d" \
"./Sources/Events_c.d" \
"./Sources/LED_BATT_c.d" \
"./Sources/PWM_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/BATT_c.obj \
./Sources/DEMARRAGE_c.obj \
./Sources/Events_c.obj \
./Sources/LED_BATT_c.obj \
./Sources/PWM_c.obj \
./Sources/RECEPTION_C.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/BATT_c.obj: ../Sources/BATT.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/BATT.args" -ObjN="Sources/BATT_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/DEMARRAGE_c.obj: ../Sources/DEMARRAGE.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/DEMARRAGE.args" -ObjN="Sources/DEMARRAGE_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Events.args" -ObjN="Sources/Events_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/LED_BATT_c.obj: ../Sources/LED_BATT.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/LED_BATT.args" -ObjN="Sources/LED_BATT_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/PWM_c.obj: ../Sources/PWM.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/PWM.args" -ObjN="Sources/PWM_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/RECEPTION_C.obj: ../Sources/RECEPTION.C
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/RECEPTION.args" -ObjN="Sources/RECEPTION_C.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.C
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


