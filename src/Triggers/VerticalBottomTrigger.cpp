/*
 * VerticalBottomTrigger.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: CW
 */

#include <Triggers/VerticalBottomTrigger.h>
#include <Robot.h>

VerticalBottomTrigger::VerticalBottomTrigger()
{
}

bool VerticalBottomTrigger::Get()
{
	if (!Robot::VerticalArmMovmentSubsystem->IsOperatorControlled())
		return false;

	return Robot::VerticalArmMovmentSubsystem->AtBottom();
}
