/*
 * VerticalArmMovment.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Devin
 */

#include <Subsystems/VerticalArmMovment.h>
#include "RobotMap.h"

const double ScaleHeightMinimum = 4.0;
const double ScaleHeightMaximum = 6.0;
const double ScalePositionMinimum = 15000;
const double ScalePositionMaximum = 30000;
const double ScaleConversionSlope = (ScalePositionMaximum-ScalePositionMinimum)/(ScaleHeightMaximum-ScaleHeightMinimum);

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

void VerticalArmMovment::MoveArm(CubeVerticalPlace target, double scaleHeight)
{
	double position = 0;

	switch (target)
	{
	case Exchange:
		position = 1000;
		break;

	case Level2:
		position = 2000;
		break;

	case Level3:
		position = 3000;
		break;

	case Portal:
		position = 4000;
		break;

	case Switch:
		position = 5000;
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
