/*
 * WheelTracking.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#include "Commands/WheelTrackingCommand.h"
#include "Robot.h"

WheelTrackingCommand::WheelTrackingCommand() : frc::Command("WheelTracking")
{
	Requires(Robot::MotionTrackingSubsystem.get());
}

void WheelTrackingCommand::Execute()
{
	Robot::MotionTrackingSubsystem->UpdateWheels();
}

bool WheelTrackingCommand::IsFinished()
{
	return false;
}
