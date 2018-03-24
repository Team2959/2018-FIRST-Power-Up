/*
 * RotateRelitiveAngleCommand.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: CW
 */

#include <Commands/Auto/RotateRelativeAngleCommand.h>
#include <robot.h>
#include <SmartDashboard/SmartDashboard.h>
#include "Subsystems/MotionTracking.h"

RotateRelativeAngleCommand::RotateRelativeAngleCommand(double angle, double speed) :
	m_inputAngle{ angle }, m_targetAngle{ 0.0 }, m_startAngle{0.0},
	m_speed{ fabs(speed) }, m_lastSpeed{0.0},
	m_readingOffset{0.0}, m_atTarget{false}
{
	Requires(Robot::DriveTrainSubsystem.get());
}

double NormalizeAngle(double angle)
{
	while(angle < 0.0)
		angle += 2.0 * Pi;
	while(angle >= 2.0 * Pi)
		angle -= 2.0 * Pi;
	return angle;
}

void RotateRelativeAngleCommand::Initialize()
{
	m_startAngle = NormalizeAngle(Robot::MotionTrackingSubsystem->GetAngle());
	auto angleRad{NormalizeAngle(m_inputAngle)};
	m_targetAngle = m_startAngle + angleRad;

	if (m_targetAngle > 2.0 * Pi)
		m_readingOffset = 2.0 * Pi;
	else if (m_targetAngle < 0)
		m_readingOffset = -2.0 * Pi;
	else
		m_readingOffset = 0.0;

	if(angleRad > Pi)
		m_speed = -m_speed;

	m_atTarget = false;
	std::cout << "RotateRelative - " << m_startAngle << ',' << m_targetAngle << ',' << m_readingOffset << ',' << m_speed << '\n';
}

void RotateRelativeAngleCommand::Execute()
{
	auto	currentAngle{NormalizeAngle(Robot::MotionTrackingSubsystem->GetAngle()) + m_readingOffset};
	double	rotationSpeed;

	std::cout << "**" << currentAngle << '\n';
	if(m_speed > 0.0)	// If turning counterclockwise
	{
		if(currentAngle > m_targetAngle)
		{
			rotationSpeed = 0.0;
			m_atTarget = true;
		}
		else
			rotationSpeed = fmin(m_lastSpeed + Acceleration, m_speed);
	}
	else
	{
		if(currentAngle < m_targetAngle)
		{
			rotationSpeed = 0.0;
			m_atTarget = true;
		}
		else
			rotationSpeed = fmax(m_lastSpeed - Acceleration, m_speed);
	}
	std::cout << "--" << rotationSpeed << '\n';
	Robot::DriveTrainSubsystem->Drive(0.0, 0.0, rotationSpeed);
}

bool RotateRelativeAngleCommand::IsFinished()
{
	return m_atTarget;
}

void RotateRelativeAngleCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0.0, 0.0, 0.0);
}

void RotateRelativeAngleCommand::Interrupted()
{
	End();
}
