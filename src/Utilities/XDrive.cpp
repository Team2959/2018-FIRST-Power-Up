/*
 * XDrive.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: TuffyPelly
 */

#include <Utilities/XDrive.h>
#include "SmartDashboard/SendableBuilder.h"
#include "RobotMap.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>

const double MaxRPM = 4000.0;

XDrive::XDrive()
{
	m_frontLeftMotor.reset(new WPI_TalonSRX(Front_LEFT_DRIVE_MOTOR_CAN));
	m_backLeftMotor.reset(new WPI_TalonSRX(Back_Left_DRIVE_MOTOR_CAN));
	m_frontRightMotor.reset(new WPI_TalonSRX(Front_Right_DRIVE_MOTOR_CAN));
	m_backRightMotor.reset(new WPI_TalonSRX(Back_Right_DRIVE_MOTOR_CAN));

	m_frontLeftMotor.get()->SetName("DriveTrain", "Front Left");
	m_frontRightMotor.get()->SetName("DriveTrain", "Front Right");
	m_backRightMotor.get()->SetName("DriveTrain", "Rear Right");
	m_backLeftMotor.get()->SetName("DriveTrain", "Rear Left");

	AddChild(m_frontLeftMotor);
	AddChild(m_frontRightMotor);
	AddChild(m_backRightMotor);
	AddChild(m_backLeftMotor);
	static int instances = 0;
	++instances;
	SetName("DifferentialDrive", instances);

		// Need more motor initialization when adding encoders
		//   ConfigSelectedFeedbackSensor
		//   SetSensorPhase  ??
		//   ConfigNominalOutputForward (and Backward; Peak Forward and backward)
		//   closed loop gains-> Config_kF; kP; kI; kD
}

void XDrive::Drive(double magnitude, double totalAngle, double rotation)
{
	// fmod does floating point (real number) modulus
	double theta = fmod(totalAngle, QuarterPi);
	// trunc returns the integral part of the number
	int evenOdd = trunc(totalAngle / QuarterPi);
	if (evenOdd % 2 == 0)
		theta = QuarterPi - theta;

	// We do not have to worry about divide by zero,
	// because theta is limited to 0 to Pi/4,
	// which gives cos(theta) a range of 1.0 to ~0.707
	// set Mfinal = maginitude * 1 / cos(theta)
	double mFinal = magnitude / cos(theta);

	double calculationAngle = totalAngle - QuarterPi;
	double motorA = mFinal * cos(calculationAngle);
	double motorB = -1* mFinal * sin(calculationAngle);

	double motorC = -motorA;
	double motorD = -motorB;

	// Factor in rotation component
	motorA = motorA + rotation;
	motorB = motorB + rotation;
	motorC = motorC + rotation;
	motorD = motorD + rotation;

	// Finds the maximum of 1 or motorA, motorB, motorC, and motorD
	double maxCalcMagnitude = fmax(1.0, fabs(motorA));
	maxCalcMagnitude = fmax(maxCalcMagnitude, fabs(motorB));
	maxCalcMagnitude = fmax(maxCalcMagnitude, fabs(motorC));
	maxCalcMagnitude = fmax(maxCalcMagnitude, fabs(motorD));

	if (maxCalcMagnitude > 1.0)
	{
		// Scaling motor outputs by the maxCalcMagnitude
		motorA = motorA / maxCalcMagnitude;
		motorB = motorB / maxCalcMagnitude;
		motorC = motorC / maxCalcMagnitude;
		motorD = motorD / maxCalcMagnitude;
	}

//	SmartDashboard::PutNumber("Motor A final", motorA);
//	SmartDashboard::PutNumber("Motor B final", motorB);

	// send value (-1..1) to motors
	// temporary, until encoders are added and send with velocity
	m_frontLeftMotor->Set(motorA);
	m_frontRightMotor->Set(motorB);
	m_backRightMotor->Set(motorC);
	m_backLeftMotor->Set(motorD);

	// Convert 500 RPM to units/ 100ms
	//  4096 [Units/Rev] * 500 [RPM] / 600 [100 ms/min]
	//    e.g Target Velocity = motorA * 500 * 4096 / 600

	// scaling to Units per 100ms and sending to the motors
//	m_FrontLeftMotor->Set(ControlMode::Velocity, motorA * MaxRPM);
//	m_FrontRightMotor->Set(ControlMode::Velocity, motorB * MaxRPM);
//	m_BackRightMotor->Set(ControlMode::Velocity, motorC * MaxRPM);
//	m_BackLeftMotor->Set(ControlMode::Velocity, motorD * MaxRPM);

	  m_safetyHelper.Feed();
}

void XDrive::StopMotor()
{
	m_frontLeftMotor->StopMotor();
	m_frontRightMotor->StopMotor();
	m_backRightMotor->StopMotor();
	m_backLeftMotor->StopMotor();
	m_safetyHelper.Feed();
}

void XDrive::GetDescription(llvm::raw_ostream& desc) const
{
	desc << "XDrive";
}

void XDrive::InitSendable(frc::SendableBuilder& builder)
{
	builder.SetSmartDashboardType("XDrive");

//  builder.AddDoubleProperty("Left Motor Speed",
//                            [=]() { return m_leftMotor.Get(); },
//                            [=](double value) { m_leftMotor.Set(value); });
//  builder.AddDoubleProperty("Right Motor Speed",
//                            [=]() { return -m_rightMotor.Get(); },
//                            [=](double value) { m_rightMotor.Set(-value); });
}
