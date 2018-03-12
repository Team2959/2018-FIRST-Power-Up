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

VerticalBottomTrigger::~VerticalBottomTrigger()
{
}

bool VerticalBottomTrigger::Get()
{
	return Robot::VerticalArmMovmentSubsystem->AtBottom();
}
