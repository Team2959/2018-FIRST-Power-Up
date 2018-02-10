/*
 * VerticalArmMovment.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Devin
 */

#include "RobotMap.h"
#include <Commands/VerticalMovementCommand.h>
#include <math.h>
#include <Subsystems/VerticalArmMovement.h>

 // approximately 24" of travel with diameter of 1.08 for an encoder with 4096 ticks
const double GearDiameter = Pi * 1.08;
const double DistanceToTicksFactor = 4096 / GearDiameter;

const double ScaleHeightMinimum = 4.0;
const double ScaleHeightMaximum = 6.0;
const double ScalePositionMaximum = 100000;
const double ScalePositionMinimum = ScalePositionMaximum - 24 * DistanceToTicksFactor;
const double ScaleConversionSlope = (ScalePositionMaximum-ScalePositionMinimum)/(ScaleHeightMaximum-ScaleHeightMinimum);

const int ExchangePosition = 3.5 * DistanceToTicksFactor;
const int Level2Position = 16.5 * DistanceToTicksFactor;
const int SwitchPosition = 24.5 * DistanceToTicksFactor;
const int PortalPosition = 25.5 * DistanceToTicksFactor;
const int Level3Position = 27.5 * DistanceToTicksFactor;

VerticalArmMovement::VerticalArmMovement() : frc::Subsystem("VerticalArmMovmentSubsystem"),
	m_cubeLiftMotor {CUBE_VERTICAL_MOTOR_CAN}
{
	m_cubeLiftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
	m_cubeLiftMotor.Config_kF(0, 0.275, 0);
	m_cubeLiftMotor.Config_kP(0, 1, 0);
//	m_cubeLiftMotor.Config_kI(0, 0.0045, 0);
//	m_cubeLiftMotor.Config_IntegralZone(0, 300, 0);
	m_cubeLiftMotor.SetSensorPhase(true);
	m_cubeLiftMotor.SetSelectedSensorPosition(0,0,0);
	m_cubeLiftMotor.Set(ControlMode::Position, 0);
}

void VerticalArmMovement::InitDefaultCommand()
{
	SetDefaultCommand(new VerticalMovementCommand());
}

void VerticalArmMovement::MoveArm(CubeVerticalPlace target, double scaleHeight)
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

	//std::cout << "Arm Position " << position << "\n";
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
}

bool VerticalArmMovement::IsAtPosition(CubeVerticalPlace target, double scaleHeight)
{
	auto position = m_cubeLiftMotor.GetSensorCollection().GetPulseWidthPosition();
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

	return fabs(position - targetPosition) < 50;
}
