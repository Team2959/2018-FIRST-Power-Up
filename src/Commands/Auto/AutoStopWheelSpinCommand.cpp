/*
 * AutoStopWheelSpinCommand.cpp
 *
 *  Created on: Apr 3, 2018
 *      Author: CW
 */

#include <Commands/Auto/AutoStopWheelSpinCommand.h>
#include "Robot.h"

AutoStopWheelSpinCommand::AutoStopWheelSpinCommand()
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

bool AutoStopWheelSpinCommand::IsFinished()
{
	return Robot::CubeDeliverySubsystem->CubePresent();
}

void AutoStopWheelSpinCommand::End()
{
	Robot::CubeDeliverySubsystem->StopWheels();
}

void AutoStopWheelSpinCommand::Interrupted()
{
	End();
}
