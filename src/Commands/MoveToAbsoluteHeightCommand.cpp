/*
 * MoveToAbsoluteHeightCommand.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: CW
 */

#include <Commands/MoveToAbsoluteHeightCommand.h>
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>

MoveToAbsoluteHeightCommand::MoveToAbsoluteHeightCommand() : frc::Command("MoveToAbsoluteHeight")
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void MoveToAbsoluteHeightCommand::Initialize()
{
	double height = frc::SmartDashboard::GetNumber("Absolute Position", 0);

	Robot::VerticalArmMovmentSubsystem->MoveToAbsoluteHeight(height);
}

bool MoveToAbsoluteHeightCommand::IsFinished()
{
	return true;
}
