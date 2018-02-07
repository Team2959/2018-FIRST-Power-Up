/*
 * GrabCubeCommand.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#include "Commands/OpeningAndClosingArmsCommand.h"
#include "Robot.h"

OpeningAndClosingArmsCommand::OpeningAndClosingArmsCommand() : frc::TimedCommand("OpeningAndClosingArms", 1.0)
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void OpeningAndClosingArmsCommand::Initialize()
{
	bool armsAreOpen = Robot::CubeDeliverySubsystem->ArmsAreOpen();
	
	if (armsAreOpen)
	{
		Robot::CubeDeliverySubsystem->SpinWheelsIn();
		Robot::CubeDeliverySubsystem->CloseArms();
	}
	else
	{
		Robot::CubeDeliverySubsystem->OpenArms();
	}
}

void OpeningAndClosingArmsCommand::End()
{
	bool armsAreOpen = Robot::CubeDeliverySubsystem->ArmsAreOpen();
	if (armsAreOpen == false)
	{
		Robot::CubeDeliverySubsystem->StopWheels();
	}
}

void OpeningAndClosingArmsCommand::Interrupted()
{
	End();
}
