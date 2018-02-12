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

bool OpeningAndClosingArmsCommand::IsFinished()
{
	bool timeExpired = frc::TimedCommand::IsFinished();

	if (Robot::CubeDeliverySubsystem->ArmsAreOpen())
	{
		return timeExpired;
	}

	if (timeExpired)
	{
		return true;
	}

	return Robot::CubeDeliverySubsystem->CubePresent();
}

void OpeningAndClosingArmsCommand::End()
{
	if (Robot::CubeDeliverySubsystem->ArmsAreOpen())
	{
		Robot::CubeDeliverySubsystem->SpinWheelsIn();
	}
	else
	{
		Robot::CubeDeliverySubsystem->StopWheels();
	}
}

void OpeningAndClosingArmsCommand::Interrupted()
{
	End();
}
