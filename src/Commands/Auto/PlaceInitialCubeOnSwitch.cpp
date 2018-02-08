/*
 * AutoPlaceInitialCubeOnSwitch.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: JWB
 */

#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>
#include "PlaceInitialCubeOnSwitch.h"

using namespace frc;

PlaceInitialCubeOnSwitchCommand::PlaceInitialCubeOnSwitchCommand() : Command("PlaceInitialCubeOnSwitch") { }

void PlaceInitialCubeOnSwitchCommand::Execute() { _commands.Run(); }
void PlaceInitialCubeOnSwitchCommand::Interrupted() { _commands.Cancel(); }
bool PlaceInitialCubeOnSwitchCommand::IsFinished() { return _commands.IsCompleted(); }

void PlaceInitialCubeOnSwitchCommand::Initialize()
{
	for(auto i = 0; i < 1000; ++i)
		std::cout << "NoData\n";

	auto	gameData{frc::DriverStation::GetInstance().GetGameSpecificMessage()};
	if(gameData.size() < 1)
		return;
	auto	switchOnLeft{gameData[0] == 'L'};	// True iff switch is on the left

	frc::SmartDashboard::PutNumber("Location - ****", (int)switchOnLeft );
	// Add commands to the group for each step
	// Identify centroid of block pyramid
	// Turn toward direction of switchOnLeft until the reflective tape is centered in field of view
	// Drive until we are close enough.  By:  identified tape block(s) are large enough or proximity sensor trips.
	// Drop the cube on switch
	for(auto i = 0; i < 1000; ++i)
	std::cout << "Switch on left - " << switchOnLeft << '\n';
	_commands.Start();
}


