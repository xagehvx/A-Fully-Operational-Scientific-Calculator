################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/STM/include/startup_stm32g031k8tx.s 

C_SRCS += \
../bsp.c \
../calc.c \
../display.c \
../keypad.c \
../main.c \
C:/STM/include/system_stm32g0xx.c 

OBJS += \
./bsp.o \
./calc.o \
./display.o \
./keypad.o \
./main.o \
./startup_stm32g031k8tx.o \
./system_stm32g0xx.o 

S_DEPS += \
./startup_stm32g031k8tx.d 

C_DEPS += \
./bsp.d \
./calc.d \
./display.d \
./keypad.d \
./main.d \
./system_stm32g0xx.d 


# Each subdirectory must supply rules for building sources it contributes
bsp.o: ../bsp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"bsp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
calc.o: ../calc.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"calc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
display.o: ../display.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"display.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
keypad.o: ../keypad.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
main.o: ../main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
startup_stm32g031k8tx.o: C:/STM/include/startup_stm32g031k8tx.s
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g -c -x assembler-with-cpp -MMD -MP -MF"startup_stm32g031k8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
system_stm32g0xx.o: C:/STM/include/system_stm32g0xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"system_stm32g0xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

