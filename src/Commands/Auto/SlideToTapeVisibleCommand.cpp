/*
 * SlideToTapeVisibleCommand.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Kevin
 */

#include <SmartDashboard/SmartDashboard.h>
#include <Commands/Auto/SlideToTapeVisibleCommand.h>


SlideToTapeVisibleCommand::SlideToTapeVisibleCommand(Side nearSwitchSide)
{
	bool startFarLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Far Left?", true);

		if (startFarLeft)
		{

		}

}

SlideToTapeVisibleCommand::~SlideToTapeVisibleCommand()
{
	// TODO Auto-generated destructor stub
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
