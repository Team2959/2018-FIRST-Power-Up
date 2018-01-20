/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#include <Subsystems/DriveTrain.h>
#include "RobotMap.h"
#include <WPILib.h>
#include "Commands/DriveWithJoystick.h"

const double QuarterPi = Pi / 4.0;

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	m_FrontLeftMotor.reset(new WPI_TalonSRX(Front_LEFT_DRIVE_MOTOR_CAN));
	m_BackLeftMotor.reset(new WPI_TalonSRX(Back_Left_DRIVE_MOTOR_CAN));
	m_FrontRightMotor.reset(new WPI_TalonSRX(Front_Right_DRIVE_MOTOR_CAN));
	m_BackRightMotor.reset(new WPI_TalonSRX(Back_Right_DRIVE_MOTOR_CAN));
}

DriveTrain::~DriveTrain()
{
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::XDrive(std::shared_ptr<frc::Joystick>)
{
	// use the joystick to drive!!
}

void DriveTrain::XDrive(double magnitude, double totalAngle, double rotation)
{
	double theta = totalAngle % QuarterPi;
}
