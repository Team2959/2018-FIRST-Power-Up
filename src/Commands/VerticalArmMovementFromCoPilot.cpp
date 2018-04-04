/*
 * VerticleMovementCommand.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: Andrew
 */

#include <Commands/VerticalArmMovementFromCoPilot.h>
#include "Robot.h"

VerticalArmMovementFromCoPilot::VerticalArmMovementFromCoPilot() : frc::Command("VerticalMovement")
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void VerticalArmMovementFromCoPilot::Execute()
{
	if (!Robot::VerticalArmMovmentSubsystem->IsOperatorControlled())
		return;

	double axis = Robot::oi->GetButtonBox()->GetRawAxis(0);
	// convert from -1 .. 1 to 0 .. 1 range
	axis = (axis + 1.0) / 2.0;
	Robot::VerticalArmMovmentSubsystem->MoveArmToHeight(axis);
}

bool VerticalArmMovementFromCoPilot::IsFinished()
{
	return false;
}
