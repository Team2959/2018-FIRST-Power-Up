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
	return Robot::VerticalArmMovmentSubsystem->IsAtHeight(m_height);
}

void MoveToVerticalCubePositionCommand::Interrupted()
{
	End();
}

void MoveToVerticalCubePositionCommand::End()
{
	Robot::VerticalArmMovmentSubsystem->StopAtHeight();
}
