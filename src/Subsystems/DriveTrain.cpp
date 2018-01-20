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

const double QuarterPi = Pi / 4.0;
const double MaxRPM = 4000.0;

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	m_FrontLeftMotor.reset(new WPI_TalonSRX(Front_LEFT_DRIVE_MOTOR_CAN));
	m_BackLeftMotor.reset(new WPI_TalonSRX(Back_Left_DRIVE_MOTOR_CAN));
	m_FrontRightMotor.reset(new WPI_TalonSRX(Front_Right_DRIVE_MOTOR_CAN));
	m_BackRightMotor.reset(new WPI_TalonSRX(Back_Right_DRIVE_MOTOR_CAN));

	// Need more motor initialization when adding encoders
	//   ConfigSelectedFeedbackSensor
	//   SetSensorPhase  ??
	//   ConfigNominalOutputForward (and Backward; Peak Forward and backward)
	//   closed loop gains-> Config_kF; kP; kI; kD
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
	// fmod does floating point (real number) modulus
	double theta = fmod(totalAngle, QuarterPi);
	// trunc returns the integral part of the number
	int evenOdd = (int)trunc(totalAngle / QuarterPi) % 2;
	if (evenOdd == 0)
		theta = QuarterPi - theta;

	// We do not have to worry about divide by zero,
	// because theta is limited to 0 to Pi/4,
	// which gives cos(theta) a range of 1.0 to ~0.707
	// set Mfinal = maginitude * 1 / cos(theta)
	double mFinal = magnitude / cos(theta);

	double motorA = -1 * mFinal * sin(totalAngle - QuarterPi);
	double motorB = mFinal * cos(totalAngle - QuarterPi);
	double motorC = -motorA;
	double motorD = -motorB;

	// Factor in rotation component
	motorA = motorA + rotation;
	motorB = motorB + rotation;
	motorC = motorC + rotation;
	motorD = motorD + rotation;

	// Finds the maximum of 1 or motorA, motorB, motorC, and motorD
	double maxCalcMagnitude = fmax(1.0, abs(motorA));
	maxCalcMagnitude = fmax(maxCalcMagnitude, abs(motorB));
	maxCalcMagnitude = fmax(maxCalcMagnitude, abs(motorC));
	maxCalcMagnitude = fmax(maxCalcMagnitude, abs(motorD));

	// Scaling motor outputs by the maxCalcMagnitude
	motorA = motorA / maxCalcMagnitude;
	motorB = motorB / maxCalcMagnitude;
	motorC = motorC / maxCalcMagnitude;
	motorD = motorD / maxCalcMagnitude;

	// send value (-1..1) to motors
	// temporary, until encoders are added and send with velocity
	m_FrontLeftMotor->Set(motorA);
	m_FrontRightMotor->Set(motorB);
	m_BackRightMotor->Set(motorC);
	m_BackLeftMotor->Set(motorD);

	// Convert 500 RPM to units/ 100ms
	//  4096 [Units/Rev] * 500 [RPM] / 600 [100 ms/min]
	//    e.g Target Velocity = motorA * 500 * 4096 / 600

	// scaling to Units per 100ms and sending to the motors
//	m_FrontLeftMotor->Set(ControlMode::Velocity, motorA * MaxRPM);
//	m_FrontRightMotor->Set(ControlMode::Velocity, motorB * MaxRPM);
//	m_BackRightMotor->Set(ControlMode::Velocity, motorC * MaxRPM);
//	m_BackLeftMotor->Set(ControlMode::Velocity, motorD * MaxRPM);
}
