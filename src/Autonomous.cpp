/*
 * Autonomous.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: Kevin
 */

#include <Autonomous.h>
#include <iostream>
#include <SmartDashboard/SmartDashboard.h>
#include <DriverStation.h>
#include "Commands/Auto/DriveStraightCommand.h"
#include "Commands/Auto/MyAutoCommand.h"
#include "Commands/Auto/PlaceInitialCubeOnSwitch.h"
#include "Commands/Auto/PlaceOnLeftSwitchCommandGroup.h"

Autonomous::Autonomous()
{
	m_chooser.AddDefault("Default Auto", AutoCommand::Default);
	m_chooser.AddObject("Drive Straight", AutoCommand::DriveStraight);
	m_chooser.AddObject("Place Initial Cube On Switch", AutoCommand::PlaceInitialCubeOnSwitch);
	m_chooser.AddObject("Place Cube On Left Switch", AutoCommand::PlaceCubeOnLeftSwitch);
	frc::SmartDashboard::PutData("Autonomous Command", &m_chooser);
}

void Autonomous::AutoInit()
{
	bool hasGameData = false;
	bool switchOnLeft = false;
	bool scaleOnLeft = false;
	bool opponentSwitchOnLeft = false;

	// Add code to read switch/scale state from Field Management System
	// https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details
	auto gameData{frc::DriverStation::GetInstance().GetGameSpecificMessage()};
	if (gameData.size() < 3)
	{
		std::cout << "AutonomousInit - No game data.\n";
	}
	else
	{
		hasGameData = true;
		switchOnLeft = gameData[0] == 'L';
		scaleOnLeft = gameData[1] == 'L';
		opponentSwitchOnLeft = gameData[2] == 'L';
	}
	std::cout << "Auto Has Game Data - " << hasGameData << '\n';
	std::cout << "Switch on left - " << switchOnLeft << '\n';
	std::cout << "Scale on left - " << scaleOnLeft << '\n';
	std::cout << "Opponent switch on left - " << opponentSwitchOnLeft << '\n';

//	std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
//	if (autoSelected == "Drive Straight")
//	{
//		m_autonomousCommand = &m_driveStraightAuto;
//	}
//	else
//	{
//		m_autonomousCommand = &m_defaultAuto;
//	}

	std::cout << "AutonomousInit - 1\n";
	switch(m_chooser.GetSelected())
	{
	case AutoCommand::Default:
		m_autonomousCommand = std::make_unique<MyAutoCommand>();
		break;
	case AutoCommand::DriveStraight:
		m_autonomousCommand = std::make_unique<DriveStraightCommand>(5.0);
		break;
	case AutoCommand::PlaceInitialCubeOnSwitch:
		m_autonomousCommand = std::make_unique<PlaceInitialCubeOnSwitchCommand>();
		break;
	case AutoCommand::PlaceCubeOnLeftSwitch:
		m_autonomousCommand = std::make_unique<PlaceOnLeftSwitchCommandGroup>();
		break;
	}

	std::cout << "AutonomousInit - 2\n";

	if(m_autonomousCommand)
	{
		std::cout << "Starting -- " << m_autonomousCommand->GetName() << '\n';
		m_autonomousCommand->Start();
	}
}

void Autonomous::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (m_autonomousCommand)
	{
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}
