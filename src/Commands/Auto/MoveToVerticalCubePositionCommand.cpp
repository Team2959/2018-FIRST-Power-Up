/*
 * MoveToVerticalCubePositionCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Andrew
 */

#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Robot.h>

MoveToVerticalCubePositionCommand::MoveToVerticalCubePositionCommand(double height) : frc::Command("MoveToVerticalCubePosition")
{
	m_height = height;
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void MoveToVerticalCubePositionCommand::Execute()
{
	Robot::VerticalArmMovmentSubsystem->MoveToAbsoluteHeight(m_height);
}

bool MoveToVerticalCubePositionCommand::IsFinished()
{
	if (fabs(m_height) < 2000 && Robot::VerticalArmMovmentSubsystem->AtBottom())
	{
		return true;
	}
	return Robot::VerticalArmMovmentSubsystem->IsAtHeight(m_height);
}

void MoveToVerticalCubePositionCommand::Interrupted()
{
	End();
}

void MoveToVerticalCubePositionCommand::End()
{
	if (fabs(m_height) < 2000 && Robot::VerticalArmMovmentSubsystem->AtBottom())
	{
		Robot::VerticalArmMovmentSubsystem->AtBottomReset();
	}
	else
	{
		Robot::VerticalArmMovmentSubsystem->StopAtHeight();
	}
}
