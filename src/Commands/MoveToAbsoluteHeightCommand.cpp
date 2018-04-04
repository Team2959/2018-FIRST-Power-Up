/*
 * MoveToAbsoluteHeightCommand.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: CW
 */

#include <Commands/MoveToAbsoluteHeightCommand.h>
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>

MoveToAbsoluteHeightCommand::MoveToAbsoluteHeightCommand(double height) : frc::Command("MoveToAbsoluteHeight"),
	m_startHeight{0}, m_targetSteppingHeight{0}, m_targetHeight{height}, m_count{0}
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void MoveToAbsoluteHeightCommand::Initialize()
{
	m_startHeight = Robot::VerticalArmMovmentSubsystem->CurrentPosition();
	m_targetSteppingHeight = fabs(m_startHeight) + 7500;
	m_count = 0;
}

void MoveToAbsoluteHeightCommand::Execute()
{
	double target = m_targetHeight;
	m_count++;
	if (fabs(m_startHeight) < m_targetSteppingHeight)
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

bool MoveToAbsoluteHeightCommand::IsFinished()
{
	return Robot::VerticalArmMovmentSubsystem->IsAtHeight(m_targetHeight);
}

void MoveToAbsoluteHeightCommand::Interrupted()
{
	End();
}

void MoveToAbsoluteHeightCommand::End()
{
	Robot::VerticalArmMovmentSubsystem->StopAtHeight();
}
