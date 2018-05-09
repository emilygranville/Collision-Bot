#include "Robot.h"

// - When you have class members that are objects, you need to initialize them using an
//   initializer list, which can be seen below.
// - For every member object, you just call the associated constructor and pass in any
//   necessary inputs

Robot::Robot() :
	ahrs(SPI::Port::kMXP),
	seconds(),
	FrontLeftMotor(1),
	BackLeftMotor(2),
	FrontRightMotor(3),
	BackRightMotor(4),
	LeftMotors(FrontLeftMotor, BackLeftMotor),
	RightMotors(FrontRightMotor, BackRightMotor),
	DriveController(0),
	DriveTrain(LeftMotors, RightMotors),
	newAccel(ahrs.GetWorldLinearAccelX()),
	oldAccel(0),
	timeNew(0),
	timeOld(seconds.Get()),
	timeCollision(-10)
{
	//int num = int(4);
}


void Robot::RobotInit()
{

}



START_ROBOT_CLASS(Robot);
