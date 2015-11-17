################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Comunicacao.cpp \
../src/Extern.cpp 

OBJS += \
./src/Comunicacao.o \
./src/Extern.o 

CPP_DEPS += \
./src/Comunicacao.d \
./src/Extern.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/fagnerpsantos/Developer/Arduino/sistemas-embarcados/cpp/comunicacaoSensores/include" -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


