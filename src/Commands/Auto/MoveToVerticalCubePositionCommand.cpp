/*
 * MoveToVerticalCubePositionCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Andrew
 */

#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Robot.h>

MoveToVerticalCubePositionCommand::MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace target) : frc::Command("MoveToVerticalCubePosition")
{
	m_target = target;
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void MoveToVerticalCubePositionCommand::Execute()
{
	Robot::VerticalArmMovmentSubsystem->MoveArm(m_target);
}

bool MoveToVerticalCubePositionCommand::IsFinished()
{
	return Robot::VerticalArmMovmentSubsystem->IsAtPosition(m_target);
}
