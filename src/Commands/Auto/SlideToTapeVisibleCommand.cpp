/*
 * SlideToTapeVisibleCommand.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Aria
 */

#include <Commands/Auto/SlideToTapeVisibleCommand.h>
#include <SmartDashboard/SmartDashboard.h>

SlideToTapeVisibleCommand::SlideToTapeVisibleCommand(Side nearSwitchSide)
{
	bool startFarLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Left?", true);

	if (startFarLeft)
	{

	}
}

void SlideToTapeVisibleCommand::Initialize()
{

}

void SlideToTapeVisibleCommand::Execute()
{

}

bool SlideToTapeVisibleCommand::IsFinished()
{
	return true;
}

void SlideToTapeVisibleCommand::End()
{

}

void SlideToTapeVisibleCommand::Interrupted()
{

}
