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
	m_isOperatorControlled{false},
	m_count{0}
{
	m_cubeLiftMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute, 0, 0);
	m_cubeLiftMotor.Config_kF(0, 0, 0);

	m_cubeLiftMotor.Config_kP(0, 0.4, 0);
	m_cubeLiftMotor.Config_kI(0, 0, 0);
//	m_cubeLiftMotor.Config_IntegralZone(0, 300, 0);
	m_cubeLiftMotor.SetSensorPhase(false);
	m_cubeLiftMotor.SetSelectedSensorPosition(0,0,0);

	m_cubeLiftMotor.ConfigPeakOutputForward(1.00, 0);	// Competition Bot
	m_cubeLiftMotor.ConfigPeakOutputReverse(-1.00, 0);	// Competition Bot
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
	SafeMoveToAbsoluteHeight(height * ScalePositionMaximum);
//	MoveToAbsoluteHeight(height * ScalePositionMaximum);
}

void VerticalArmMovement::MoveToAbsoluteHeight(double height)
{
	frc::SmartDashboard::PutNumber("Talon Curent", m_cubeLiftMotor.GetOutputCurrent());
	m_cubeLiftMotor.Set(ControlMode::Position, height);
}

void VerticalArmMovement::SafeMoveToAbsoluteHeight(double newTarget)
{
	m_count++;

	if ((m_count % 5) != 0)
	{
		return;
	}

	// The intent of this function is to facilitate slow acceleration and deceleration
	// from a continuous stream of new commands and without having knowledge of previous commands.
	// This will function only work with a continuous stream of intended heights 
	// calling only once will not provide the intended result.  
	
	// Velocity is set in encoder ticks per 100ms. 
	// Max speed of our motor + gearbox is 180 RPM (1228.8 ticks/100ms)
	// The estimate thresholds set here will be 10% of max or ~130ticks/100ms
	double upVelocityThreshold   = 130.0;
	double downVelocityThreshold = -130.0;
	// Position thresholds are set to 5% of total height
	double upPositionThreshold   = 0.05 * ScalePositionMaximum;
	double downPositionThreshold = 0.05 * ScalePositionMaximum;

	double currentVelocity = m_cubeLiftMotor.GetSelectedSensorVelocity(0);
	double currentPosition = m_cubeLiftMotor.GetSelectedSensorPosition(0);

	double target = currentPosition; // A safe initial value

	// Is target asking to move up or down
	if (newTarget >= currentPosition) {
		// Asking to move UP
		if ((newTarget - currentPosition) < upPositionThreshold || currentVelocity > upVelocityThreshold) {
			// The mast is moving fast enough or is close enough to set the full target
			target = newTarget;
		} else if (currentVelocity < 0) {
			// If the mast is moving down it should be stopped before being moved up
			target = currentPosition;
		} else {
			// Target is set to only 20% of the way to intended target
			// As the mast moves this set point will travel upward slowly,
			// once the mast is moving though, it will be set to the intended target
			target = currentPosition + 750;
//			target = ((newTarget - currentPosition) * 0.2) + currentPosition;
		}
	} else {
		// Asking to move DOWN
		if (currentVelocity > 0) {
			// If the mast is moving up it should stop before being moved back down
			target = currentPosition;
		} else if ((currentPosition - newTarget) < downPositionThreshold && currentVelocity > downVelocityThreshold) {
			target = newTarget;
		} else {
			// Target is set to 80% of the way to the intended target,
			// this should allow the PID to slow the mast down significantly before
			// target is set to the intended target
			target = newTarget + (0.2 * (currentPosition - newTarget));
		}
	}

	m_cubeLiftMotor.Set(ControlMode::Position, target);
}

void VerticalArmMovement::StopAtHeight()
{
	MoveToAbsoluteHeight(CurrentPosition());
}

void VerticalArmMovement::AdjustAndSetHeight(double adjustment)
{
	double height = CurrentPosition();
	height += adjustment;
	m_cubeLiftMotor.Set(ControlMode::Position, height);
}

double VerticalArmMovement::CurrentPosition()
{
	return m_cubeLiftMotor.GetSelectedSensorPosition(0);
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
	return fabs(CurrentPosition() - height) < 750;
}

bool VerticalArmMovement::IsAtSwitchOrHigher()
{
	return CurrentPosition() > (SwitchPosition - 500);
}

void VerticalArmMovement::UpdateSmartDashboard()
{
	frc::SmartDashboard::PutNumber("Current Position", CurrentPosition());
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
