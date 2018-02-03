/*
 * WheelTracking.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/WheelTracking.h>
#include "Robot.h"

WheelTracking::WheelTracking() : Command("WheelTracking")
{
	Requires(Robot::MotionTrackingSubsystem.get());
}

WheelTracking::~WheelTracking()
{
}

void WheelTracking::Execute()
{
	Robot::MotionTrackingSubsystem->UpdateWheels();
}

bool WheelTracking::IsFinished()
{
	return true;
}
