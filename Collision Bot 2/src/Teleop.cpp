#include "Robot.h"

void Robot::TeleopInit()
{
	seconds.Start();
}

void Robot::TeleopPeriodic()
{
	oldAccel = newAccel;
	newAccel = ahrs.GetWorldLinearAccelX();
	timeOld = timeNew;
	timeNew = seconds.Get();
	double time = timeNew - timeOld;
	float jerk = (oldAccel - newAccel) / time;
	int maxJerkAllowed = 60;
	SmartDashboard::PutNumber("jerk", jerk);
	bool shouldRumble;
	if(jerk < -maxJerkAllowed || jerk > maxJerkAllowed){
		timeCollision = timeNew;
	}
//	if(DriveController.GetYButton()){
//			timeCollision = timeNew;
//	}
	if(timeNew - timeCollision < 1){
		DriveController.SetRumble(GenericHID::RumbleType::kLeftRumble, 1);
		DriveController.SetRumble(GenericHID::RumbleType::kRightRumble, 1);
		shouldRumble = true;
	}else{
		DriveController.SetRumble(GenericHID::RumbleType::kLeftRumble, 0);
		DriveController.SetRumble(GenericHID::RumbleType::kRightRumble, 0);
		shouldRumble = false;
	}
	SmartDashboard::PutBoolean("shouldRumble", shouldRumble);


	double speedVal = 0;
	double turnVal = 0;

	// Different Drive Schemes
	if(DriveController.GetAButton())
	{
		speedVal = DriveController.GetY(GenericHID::JoystickHand::kLeftHand);
		turnVal = DriveController.GetX(GenericHID::JoystickHand::kLeftHand);
	}
	else if(DriveController.GetBumper(GenericHID::JoystickHand::kLeftHand))
	{
		speedVal = DriveController.GetY(GenericHID::JoystickHand::kLeftHand);
		turnVal = DriveController.GetX(GenericHID::JoystickHand::kRightHand);
	}
	else if(DriveController.GetBumper(GenericHID::JoystickHand::kRightHand))
	{
		speedVal = DriveController.GetY(GenericHID::JoystickHand::kRightHand);
		turnVal = DriveController.GetX(GenericHID::JoystickHand::kLeftHand);
	}

	DriveTrain.ArcadeDrive(speedVal, turnVal);
}
