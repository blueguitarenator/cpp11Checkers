################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Board.cpp \
../Checker.cpp \
../Game.cpp \
../GameEngine.cpp \
../Square.cpp 

OBJS += \
./Board.o \
./Checker.o \
./Game.o \
./GameEngine.o \
./Square.o 

CPP_DEPS += \
./Board.d \
./Checker.d \
./Game.d \
./GameEngine.d \
./Square.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/richardjohnson/code/cpp/gtest-1.6.0/include -I/opt/local/include/gcc47/c++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


