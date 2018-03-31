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
	m_cubeLiftMotor {CUBE_VERTICAL_MOTOR_CAN},
	m_atBottomSwitch {AT_BOTTOM_LIMIT_SWITCH},
	m_isOperatorControlled{false}
{
	m_cubeLiftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
	m_cubeLiftMotor.Config_kF(0, 0, 0);

	m_cubeLiftMotor.Config_kP(0, 0.4, 0);
	m_cubeLiftMotor.Config_kI(0, 0, 0);
//	m_cubeLiftMotor.Config_IntegralZone(0, 300, 0);
	m_cubeLiftMotor.SetSensorPhase(false);
	m_cubeLiftMotor.SetSelectedSensorPosition(0,0,0);

	m_cubeLiftMotor.ConfigPeakOutputForward(1.00, 0);	// Competition Bot
	m_cubeLiftMotor.ConfigPeakOutputReverse(-0.75, 0);	// Competition Bot
//	m_cubeLiftMotor.ConfigPeakOutputForward(0.6, 0);   // Practice Bot
//	m_cubeLiftMotor.ConfigPeakOutputReverse(-1, 0);  // Practice Bot
	m_cubeLiftMotor.ConfigPeakCurrentLimit(5, 0);

	m_cubeLiftMotor.ConfigAllowableClosedloopError(0, 128, 0);
	m_cubeLiftMotor.ConfigClosedloopRamp(0, 0);

	m_cubeLiftMotor.Set(ControlMode::Position, 0);
}

void VerticalArmMovement::InitDefaultCommand()
{
	SetDefaultCommand(new VerticalArmMovementFromCoPilot());
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
	MoveToAbsoluteHeight(position);
}

void VerticalArmMovement::MoveArmToHeight(double height)
{
	height = fmax(0, height);
	height = fmin(1, height);
	MoveToAbsoluteHeight(height * ScalePositionMaximum);
}

void VerticalArmMovement::MoveToAbsoluteHeight(double height)
{
	frc::SmartDashboard::PutNumber("Talon Curent", m_cubeLiftMotor.GetOutputCurrent());
	m_cubeLiftMotor.Set(ControlMode::Position, height);
}

void VerticalArmMovement::StopAtHeight()
{
	MoveToAbsoluteHeight(m_cubeLiftMotor.GetSelectedSensorPosition(0));
}

void VerticalArmMovement::AdjustAndSetHeight(double adjustment)
{
	double height = m_cubeLiftMotor.GetSelectedSensorPosition(0);
	height += adjustment;
	m_cubeLiftMotor.Set(ControlMode::Position, height);
}

bool VerticalArmMovement::IsAtPosition(CubeVerticalPlace target, double scaleHeight)
{
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

	return IsAtHeight(targetPosition);
}

bool VerticalArmMovement::IsAtHeight(double height)
{
	return fabs(m_cubeLiftMotor.GetSelectedSensorPosition(0) - height) < 750;
}

bool VerticalArmMovement::IsAtSwitchOrHigher()
{
	return m_cubeLiftMotor.GetSelectedSensorPosition(0) > (SwitchPosition - 500);
}

void VerticalArmMovement::UpdateSmartDashboard()
{
	frc::SmartDashboard::PutNumber("Current Position", m_cubeLiftMotor.GetSelectedSensorPosition(0));
	frc::SmartDashboard::PutBoolean("At Vert Bottom", AtBottom());
}

bool VerticalArmMovement::AtBottom()
{
	return !m_atBottomSwitch.Get();
}

void VerticalArmMovement::AtBottomReset()
{
	m_cubeLiftMotor.SetSelectedSensorPosition(0,0,0);
	m_cubeLiftMotor.Set(ControlMode::Position, 0);
}
