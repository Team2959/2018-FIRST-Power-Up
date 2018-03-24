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
	m_height{height}
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void MoveToAbsoluteHeightCommand::Initialize()
{
	Robot::VerticalArmMovmentSubsystem->MoveToAbsoluteHeight(m_height);
}

bool MoveToAbsoluteHeightCommand::IsFinished()
{
	return true;
}
