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
#include <math.h>
const double Pi = 3.1415926535;
const double QuarterPi = Pi / 4.0;
const double MaxRPM = 4000.0;

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

void DriveTrain::XDrive(double magnitude, double totalAngle, double rotation)
{
	double theta = totalAngle % QuarterPi;

	double mFinal = 1/cos(theta);

	double motorA = -1*mFinal*magnitude*sin(totalAngle-QuarterPi);
	double motorB = mFinal*magnitude*cos(totalAngle-QuarterPi);
	double motorC = -motorA;
	double motorD = -motorB;

	motorA = motorA + rotation;
	motorB = motorB + rotation;
	motorC = motorC + rotation;
	motorD = motorD + rotation;

	//finds the maximum of 1 or motorA, motorB, motorC, and motorD
	double maxCalcMagnitude = 1;
	if (abs(motorA) > maxCalcMagnitude)
		maxCalcMagnitude = abs(motorA);
	if (abs(motorB) > maxCalcMagnitude)
		maxCalcMagnitude = abs(motorB);
	if (abs(motorC) > maxCalcMagnitude)
		maxCalcMagnitude = abs(motorC);
	if (abs(motorD) > maxCalcMagnitude)
		maxCalcMagnitude = abs(motorD);

	//scaling motor outputs by the maxCalcMagnitude
	motorA = motorA / maxCalcMagnitude;
	motorB = motorB / maxCalcMagnitude;
	motorC = motorC / maxCalcMagnitude;
	motorD = motorD / maxCalcMagnitude;

	// scaling to RPMs and sending to the motors
	m_FrontLeftMotor->Set(motorA * MaxRPM);
	m_FrontRightMotor->Set(motorB * MaxRPM);
	m_BackRightMotor->Set(motorC * MaxRPM);
	m_BackLeftMotor->Set(motorD * MaxRPM);
}
