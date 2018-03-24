/*
 * MoveToVerticalCubePositionCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Andrew
 */

#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Robot.h>

MoveToVerticalCubePositionCommand::MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace target, double scale) : frc::Command("MoveToVerticalCubePosition")
{
	m_target = target;
	m_scale = scale;
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void MoveToVerticalCubePositionCommand::Execute()
{
	Robot::VerticalArmMovmentSubsystem->MoveArm(m_target, m_scale);
}

bool MoveToVerticalCubePositionCommand::IsFinished()
{
	return Robot::VerticalArmMovmentSubsystem->IsAtPosition(m_target);
}
