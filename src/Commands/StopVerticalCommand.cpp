/*
 * StopVerticalCommand.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: CW
 */

#include <Commands/StopVerticalCommand.h>
#include "Robot.h"

StopVerticalCommand::StopVerticalCommand()
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void StopVerticalCommand::Execute()
{
	Robot::VerticalArmMovmentSubsystem->AtBottomReset();
}

bool StopVerticalCommand::IsFinished()
{
	return true;
}
