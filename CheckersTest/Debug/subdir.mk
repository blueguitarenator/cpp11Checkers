################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BoardTest.cpp \
../CheckerTest.cpp \
../main.cpp 

OBJS += \
./BoardTest.o \
./CheckerTest.o \
./main.o 

CPP_DEPS += \
./BoardTest.d \
./CheckerTest.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I/Users/richardjohnson/code/cpp/gtest-1.6.0/include -I/Users/richardjohnson/code/cpp/gmock-1.6.0/include -I"/Users/richardjohnson/Documents/Code/workspace" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


