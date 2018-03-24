/*
 * VerticalButtonCommand.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author:
 */

#include <Commands/VerticalButtonCommand.h>
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>

// decrement is calculated based on 20 ms periodic calls, which is 50 calls per second
// multiply 50 by the number of seconds you wish to take to lower the vertical system
VerticalButtonCommand::VerticalButtonCommand() : frc::Command("Vertical Button")
{
	m_startHeight = 0;
	m_count= 0;
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void VerticalButtonCommand::Initialize()
{
	m_startHeight = 0;
	m_count = 0;
}

void VerticalButtonCommand::Execute()
{
	double target = Robot::VerticalArmMovmentSubsystem->MaxScaleHeight() * 0.75;
	m_count++;
	if (fabs(m_startHeight) < 7500)
	{
		if ((m_count % 5) == 0)
		{
			m_startHeight += 750 * Robot::VerticalArmMovmentSubsystem->MoveDirectionMultiplier();
		}

		target = m_startHeight;
	}
	frc::SmartDashboard::PutNumber("Target Height", target);
	Robot::VerticalArmMovmentSubsystem->MoveToAbsoluteHeight(target);
}

bool VerticalButtonCommand::IsFinished()
{
	return Robot::VerticalArmMovmentSubsystem->IsAtPosition(VerticalArmMovement::Scale, 6);
}
