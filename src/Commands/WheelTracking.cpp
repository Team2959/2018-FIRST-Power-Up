/*
 * WheelTracking.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/WheelTracking.h>

WheelTracking::WheelTracking() : Command("WheelTracking")
{
	// TODO Auto-generated constructor stub
	Requires(Robot::MotionTrackingSubsystem.get());

}

WheelTracking::~WheelTracking() {
	// TODO Auto-generated destructor stub
}

void WheelTracking::Execute()
{
	Robot::MotionTrackingSubsystem->UpdateWheels();
}

