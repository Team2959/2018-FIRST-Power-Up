/*
 * VerticalArmMovment.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Devin
 */

#include <Subsystems/VerticalArmMovment.h>
#include "RobotMap.h"
#include <Commands/VerticalMovementCommand.h>
#include <math.h>

const double ScaleHeightMinimum = 4.0;
const double ScaleHeightMaximum = 6.0;
const double ScalePositionMinimum = 15000;
const double ScalePositionMaximum = 30000;
const double ScaleConversionSlope = (ScalePositionMaximum-ScalePositionMinimum)/(ScaleHeightMaximum-ScaleHeightMinimum);

const int ExchangePosition = 1000;
const int Level2Position = 2000;
const int Level3Position = 3000;
const int PortalPosition = 4000;
const int SwitchPosition = 5000;


VerticalArmMovment::VerticalArmMovment() : frc::Subsystem("VerticalArmMovmentSubsystem"),
	m_cubeLiftMotor {CUBE_VERTICAL_MOTOR_CAN}
{
	m_cubeLiftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
//	m_cubeLiftMotor.Config_kF(0, 0.275, 0);
//	m_cubeLiftMotor.Config_kP(0, 0.45, 0);
//	m_cubeLiftMotor.Config_kI(0, 0.0045, 0);
//	m_cubeLiftMotor.Config_IntegralZone(0, 300, 0);
	m_cubeLiftMotor.SetSensorPhase(true);
}

VerticalArmMovment::~VerticalArmMovment()
{
}

void VerticalArmMovment::InitDefaultCommand()
{
	SetDefaultCommand(new VerticalMovementCommand());
}

void VerticalArmMovment::MoveArm(CubeVerticalPlace target, double scaleHeight)
{
	double position = 0;

	switch (target)
	{
	case Exchange:
		position = ExchangePosition;
		break;

	case Level2:
		position = Level2Position;
		break;

	case Level3:
		position = Level3Position;
		break;

	case Portal:
		position = PortalPosition;
		break;

	case Switch:
		position = SwitchPosition;
		break;

	case Scale:
		position = ScaleConversionSlope*(scaleHeight-ScalePositionMinimum)+ScalePositionMinimum;
		break;
	}

	m_cubeLiftMotor.Set(ControlMode::Position, position);

	// From CTRE manual for 7.5.4.2. CTR Magnetic Encoder (absolute) – C++
//	/* get the decoded pulse width encoder position, 4096 units per rotation */
//	int pulseWidthPos = talon.GetSensorCollection().GetPulseWidthPosition();
//	/* get the pulse width in us, rise-to-fall in microseconds */
//	int pulseWidthUs = talon.GetSensorCollection().GetPulseWidthRiseToFallUs();
//	/* get the period in us, rise-to-rise in microseconds */
//	int periodUs = talon.GetSensorCollection().GetPulseWidthRiseToRiseUs();
//	/* get measured velocity in units per 100ms, 4096 units is one rotation */
//	int pulseWidthVel = talon.GetSensorCollection().GetPulseWidthVelocity();
//	/* is sensor plugged in to Talon */
//	bool sensorPluggedIn = false;
//	if (periodUs != 0) {
//	sensorPluggedIn = true;
//	}
//	m_cubeLiftMotor.Set();
}

bool VerticalArmMovment::IsAtPosition(CubeVerticalPlace target, double scaleHeight)
{
	auto position = m_cubeLiftMotor.GetActiveTrajectoryPosition();
	double targetPosition = 0;

	switch (target)
	{
	case Exchange:
		targetPosition = ExchangePosition;
		break;
	case Level2:
		targetPosition = Level2Position;
		break;
	case Level3:
		targetPosition = Level3Position;
		break;
	case Portal:
		targetPosition = PortalPosition;
		break;
	case Switch:
		targetPosition = SwitchPosition;
		break;
	case Scale:
		targetPosition = ScaleConversionSlope*(scaleHeight-ScalePositionMinimum)+ScalePositionMinimum;
		break;
	}

	return fabs(position - targetPosition) < 5;
}
