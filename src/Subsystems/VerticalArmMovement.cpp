/*
 * VerticalArmMovment.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Devin
 */

#include <Subsystems/VerticalArmMovement.h>
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/VerticalArmMovementFromCoPilot.h>

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
//	SetDefaultCommand(new VerticalArmMovementFromCoPilot());
}

void VerticalArmMovement::MoveArm(CubeVerticalPlace target, double scaleHeight)
{
	double position = 0;

	switch (target)
	{
	case Level1:
		position = Level1Position;
		break;
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
}

void VerticalArmMovement::MoveArmToHeight(double height)
{
	height = fmax(0, height);
	height = fmin(1, height);
	m_cubeLiftMotor.Set(ControlMode::Position, height * ScalePositionMaximum);
}

bool VerticalArmMovement::IsAtPosition(CubeVerticalPlace target, double scaleHeight)
{
	auto position = m_cubeLiftMotor.GetSelectedSensorPosition(0);

	double targetPosition = 0;

	switch (target)
	{
	case Level1:
		targetPosition = Level1Position;
		break;
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

	frc::SmartDashboard::PutNumber("Current Position", position);
	frc::SmartDashboard::PutNumber("Target Position", targetPosition);

	return fabs(position - targetPosition) < 50;
}

bool VerticalArmMovement::IsAtSwitchOrHigher()
{
	return m_cubeLiftMotor.GetSelectedSensorPosition(0) > (SwitchPosition - 500);
}
