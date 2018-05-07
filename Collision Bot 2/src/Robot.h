#ifndef ROBOT
#define ROBOT

#include <WPILib.h>
#include <AHRS.h>
#include <ctre/Phoenix.h>
using namespace frc;

class Robot: public TimedRobot
{
private:
	// Here's a breakdown of what member objects we're declaring:
	// - 4 Motor Controllers for each of the drive motors (WPI_TalonSRX)
	// - 1 Xbox Controller for controlling the robot
	// - 1 DifferentialDrive object to access ArcadeDrive
	// - 2 SpeedControllerGroups to contain the left and right side motors

    AHRS ahrs;
    Timer seconds;
	WPI_TalonSRX FrontLeftMotor;
	WPI_TalonSRX BackLeftMotor;
	WPI_TalonSRX FrontRightMotor;
	WPI_TalonSRX BackRightMotor;
	SpeedControllerGroup LeftMotors;
	SpeedControllerGroup RightMotors;
	XboxController DriveController;
	DifferentialDrive DriveTrain;
	float newAccel;
	float oldAccel;
	double timeNew;
	double timeOld;

public:
	// Here, we're declaring the following functions:
	// - Robot class constructor
	// - Virtual functions from IterativeRobot
	//      - There is an Init and Periodic variant of each (excluding RobotInit)
	//      - Remember, override is useful because it will throw a compiler error if
	//        you aren't defining a virtual function (which is inherited from the parent class)
	// - The functions will be defined in the respective cpp files

	Robot();
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};



#endif /* ROBOT */
