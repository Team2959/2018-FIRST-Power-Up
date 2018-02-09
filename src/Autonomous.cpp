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

Autonomous::Autonomous() : m_driveStraightAuto {5.0}
{
	m_chooser.AddDefault("Default Auto", &m_defaultAuto);
	m_chooser.AddObject("Drive Straight", &m_driveStraightAuto);
	m_chooser.AddObject("Place Initial Cube On Switch", &m_placeInitialCubeOnSwitch);
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

Autonomous::~Autonomous()
{
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
	m_autonomousCommand = m_chooser.GetSelected();

	for(auto i = 0; i < 10; ++i)
		std::cout << "m_autonomousCommand - " << (void*)m_autonomousCommand << '\n';
	// Chooser isn't working...figure out why
	if (m_autonomousCommand != nullptr)
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
	if (m_autonomousCommand != nullptr)
	{
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}
