/*
 * SpinArmWheelsInCommand.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#include <Commands/DeliverCubeCommand.h>
#include "Robot.h"

DeliverCubeCommand::DeliverCubeCommand() : frc::Command("DeliverCube")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void DeliverCubeCommand::Initialize()
{
	double speedAxis = Robot::oi->GetButtonBox()->GetRawAxis(1);

	if (speedAxis > 0)
	{
		speedAxis = fmax(0.25,speedAxis);
	}
	else
	{
		// Auto select speed based on button box slider input
		double autoAxis = Robot::oi->GetButtonBox()->GetRawAxis(2);
		if (autoAxis > -0.75)
		{
			// slow
			autoAxis = 0.25;
		}
		else
		{
			// fast
			autoAxis = 1;
		}
	}

	Robot::CubeDeliverySubsystem->SpinWheelsOut(speedAxis);
}

bool DeliverCubeCommand::IsFinished()
{
	return true;
}
