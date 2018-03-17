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


RotateRelativeAngleCommand::RotateRelativeAngleCommand() :
m_targetAngle{ 0.0 }, m_startAngle{0.0}, m_speed{ 0.25 }, m_lastSpeed{0.0}, m_readingOffset{0.0}, m_atTarget{false}
{
	Requires(Robot::DriveTrainSubsystem.get());
	Requires(Robot::MotionTrackingSubsystem.get());

}

void RotateRelativeAngleCommand::Initialize()
{
	m_startAngle = Robot::MotionTrackingSubsystem->GetAngle();
	auto angleDeg{frc::SmartDashboard::GetNumber("Auton Angle", 45.0)};
	while(angleDeg > 180.0)
		angleDeg -= 360.0;
	while(angleDeg < -180.0)
		angleDeg += 360.0;
	m_targetAngle = (m_startAngle + angleDeg * Pi/180.0);
	if(m_targetAngle > 2.0 * Pi)
		m_readingOffset = 2.0 * Pi;
	else if(m_targetAngle < 0)
		m_readingOffset = -2.0 * Pi;
	else
		m_readingOffset = 0.0;
	m_speed = frc::SmartDashboard::GetNumber("Auton Speed", 0.25);
	if(angleDeg < 0)
	{
		m_speed = fabs(m_speed);
	}
	else
	{
		m_speed = -fabs(m_speed);
	}
	m_atTarget = false;

	std::cout << m_startAngle << ',' << m_targetAngle << ',' << m_readingOffset << ',' << m_speed << '\n';
}

void RotateRelativeAngleCommand::Execute()
{
	auto	currentAngle{Robot::MotionTrackingSubsystem->GetAngle() + m_readingOffset};
	double	rotationSpeed;

	std::cout << "**" << currentAngle << '\n';
	if(m_speed > 0.0)	// If turning counterclockwise
	{
		if(currentAngle < m_targetAngle)
		{
			rotationSpeed = 0.0;
			m_atTarget = true;
		}
		else
			rotationSpeed = fmin(m_lastSpeed + Acceleration, m_speed);
	}
	else
	{
		if(currentAngle > m_targetAngle)
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
	Interrupted();
}

void RotateRelativeAngleCommand::Interrupted()
{
	Robot::DriveTrainSubsystem->Drive(0.0, 0.0, 0.0);
}
