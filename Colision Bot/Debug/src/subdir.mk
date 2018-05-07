################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Auto.cpp \
../src/Disabled.cpp \
../src/Robot.cpp \
../src/Teleop.cpp 

OBJS += \
./src/Auto.o \
./src/Disabled.o \
./src/Robot.o \
./src/Teleop.o 

CPP_DEPS += \
./src/Auto.d \
./src/Disabled.d \
./src/Robot.d \
./src/Teleop.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\zbreit/wpilib/cpp/current/include" -I"C:\Users\zbreit\workspace\Colision Bot\src" -I"C:\Users\zbreit/wpilib/user/cpp/include" -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


