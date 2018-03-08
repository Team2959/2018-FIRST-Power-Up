/*
 * SpinArmWheelsInCommand.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#include <Commands/DeliverCubeCommand.h>
#include "Robot.h"
#include "Subsystems/CubeDelivery.h"
#include <iostream>

DeliverCubeCommand::DeliverCubeCommand() : frc::Command("DeliverCube")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void DeliverCubeCommand::Initialize()
{
	double speedAxis = Robot::oi->GetButtonBox()->GetRawAxis(1);

	if (speedAxis > 0)
	{
		speedAxis = -speedAxis;
	}
	else if (Robot::VerticalArmMovmentSubsystem->IsAtSwitchOrHigher())
	{
		speedAxis = SpinCubeWheelsOutSlow;
	}
	else
	{
		speedAxis = SpinCubeWheelsOutFast;
	}

	Robot::CubeDeliverySubsystem->SpinWheelsOut(speedAxis);
//	Robot::CubeDeliverySubsystem->SpinWheelsOut(SpinCubeWheelsOutFast);
	std::cout << "Deliver Cube\n";
}

bool DeliverCubeCommand::IsFinished()
{
	return true;
}
