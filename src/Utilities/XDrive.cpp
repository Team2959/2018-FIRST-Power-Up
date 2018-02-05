/*
 * XDrive.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: TuffyPelly
 */

#include "Utilities/XDrive.h"
#include <SmartDashboard/SendableBuilder.h>
#include "RobotMap.h"
#include <math.h>

// Convert 500 RPM to units/ 100ms
//  4096 [Units/Rev] * 500 [RPM] / 600 [100 ms/min]
//    e.g Target Velocity = motorA * 500 * 4096 / 600
const double MaxRPM = 500.0;
const double RawToVelocity =  MaxRPM * 4096.0 / 600.0;

XDrive::XDrive()
{
	CreateAndConfigureMotorController(m_frontLeftMotor, Front_LEFT_DRIVE_MOTOR_CAN, "Front Left");
	CreateAndConfigureMotorController(m_backLeftMotor, Back_Left_DRIVE_MOTOR_CAN, "Back Left");
	CreateAndConfigureMotorController(m_frontRightMotor, Front_Right_DRIVE_MOTOR_CAN, "Front Right");
	CreateAndConfigureMotorController(m_backRightMotor, Back_Right_DRIVE_MOTOR_CAN, "Back Right");
}

void XDrive::CreateAndConfigureMotorController(std::shared_ptr<WPI_TalonSRX> motor, int canId, std::string name)
{
	motor.reset(new WPI_TalonSRX(canId));

	motor->Set(ControlMode::Velocity, 0);

	motor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 0);
	motor->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_5Ms, 0);
	motor->ConfigVelocityMeasurementWindow(1, 0);
	motor->SetSensorPhase(true);
	motor->Config_kF(0, 0.275, 0);
	motor->Config_kP(0, 0.45, 0);
	motor->Config_kI(0, 0.0045, 0);
	motor->Config_IntegralZone(0, 300, 0);

	motor.get()->SetName("XDrive", name);

	AddChild(motor);
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

	// send value (-1..1) to motors
	// temporary, until encoders are added and send with velocity
	//m_frontLeftMotor->Set(motorA);
	//m_frontRightMotor->Set(motorB);
	//m_backRightMotor->Set(motorC);
	//m_backLeftMotor->Set(motorD);

	// scaling to Units per 100ms and sending to the motors
	m_frontLeftMotor->Set(ControlMode::Velocity, motorA * RawToVelocity);
	m_frontRightMotor->Set(ControlMode::Velocity, motorB * RawToVelocity);
	m_backRightMotor->Set(ControlMode::Velocity, motorC * RawToVelocity);
	m_backLeftMotor->Set(ControlMode::Velocity, motorD * RawToVelocity);

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

	builder.AddDoubleProperty("Front Left Motor Speed",
							[=]() { return m_frontLeftMotor->Get(); },
							[=](double value) { m_frontLeftMotor->Set(ControlMode::Velocity, value); });

	builder.AddDoubleProperty("Front Right Motor Speed",
							[=]() { return m_frontRightMotor->Get(); },
							[=](double value) { m_frontRightMotor->Set(ControlMode::Velocity, value); });

	builder.AddDoubleProperty("Back Right Motor Speed",
							[=]() { return m_backRightMotor->Get(); },
							[=](double value) { m_backRightMotor->Set(ControlMode::Velocity, value); });

	builder.AddDoubleProperty("Back Left Motor Speed",
							[=]() { return m_backLeftMotor->Get(); },
							[=](double value) { m_backLeftMotor->Set(ControlMode::Velocity, value); });
}

std::shared_ptr<WPI_TalonSRX> XDrive::FlmPointer()
{
	return m_frontLeftMotor;
}

std::shared_ptr<WPI_TalonSRX> XDrive::FrmPointer()
{
	return m_frontRightMotor;
}

std::shared_ptr<WPI_TalonSRX> XDrive::BlmPointer()
{
	return m_backLeftMotor;
}

std::shared_ptr<WPI_TalonSRX> XDrive::BrmPointer()
{
	return m_backRightMotor;
}
