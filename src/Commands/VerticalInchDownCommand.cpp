/*
 * VerticalInchDownCommand.cpp
 *
 *  Created on: Mar 30, 2018
 *      Author: CW
 */

#include <Commands/VerticalInchDownCommand.h>
#include "Robot.h"

VerticalInchDownCommand::VerticalInchDownCommand()
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void VerticalInchDownCommand::Execute()
{
	if (!Robot::VerticalArmMovmentSubsystem->AtBottom())
	{
		Robot::VerticalArmMovmentSubsystem->AdjustAndSetHeight(-500);
	}
}

bool VerticalInchDownCommand::IsFinished()
{
	return Robot::VerticalArmMovmentSubsystem->AtBottom();
}

void VerticalInchDownCommand::End()
{
	Robot::VerticalArmMovmentSubsystem->StopAtHeight();
}

void VerticalInchDownCommand::Interrupted()
{
	End();
}
