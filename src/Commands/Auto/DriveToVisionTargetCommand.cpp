/*
 * DriveToVisionTargetCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include "../../Robot.h"

DriveToVisionTargetCommand::DriveToVisionTargetCommand()
{
	Requires(Robot::VisionSubsystem.get());
}

void DriveToVisionTargetCommand::Execute()
{
}

bool DriveToVisionTargetCommand::IsFinished()
{
	return false;
}

void DriveToVisionTargetCommand::End()
{
}
