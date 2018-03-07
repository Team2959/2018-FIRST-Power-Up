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
#include "Robot.h"
#include "Commands/Auto/DriveStraightCommand.h"
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include "Commands/Auto/PlaceCubeOurSideOnlyCommandGroup.h"
#include "Commands/Auto/FarLeftAndRightCommandGroup.h"

Autonomous::Autonomous()
{
	m_chooser.AddDefault("Drive Straight", AutoCommand::Default);
	m_chooser.AddObject("Center-Place Initial Cube On Switch", AutoCommand::PlaceInitialCubeOnSwitch);
	m_chooser.AddObject("Left/Right-Place Cube On Our Side", AutoCommand::PlaceCubeOnOurSide);
	m_chooser.AddObject("Side wall-Place Cube On Our Side", AutoCommand::FromOutsideWallPlaceCubeOnOurSide);
	frc::SmartDashboard::PutData("Autonomous Command", &m_chooser);

	frc::SmartDashboard::PutNumber("Auton Speed", 0.25);
	frc::SmartDashboard::PutNumber("Auton Shimmy Speed", 0.2);
	frc::SmartDashboard::PutNumber("Auton Straight To Switch Time", 1.0);
	frc::SmartDashboard::PutBoolean("Is Auton Starting Left?", true);

	m_foundGameData = false;
}

void Autonomous::AutoInit()
{
	m_foundGameData = false;
	m_autonomousCommand = nullptr;
	Robot::CubeDeliverySubsystem->CloseArms();

	StartAutonomousFromGameData();
}

void Autonomous::AutoPeriodic()
{
	// ensure we wait for game data to start autonomous
	if (!m_foundGameData && m_autonomousCommand == nullptr)
	{
		StartAutonomousFromGameData();
	}
}

void Autonomous::CancelAutonomousCommand()
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

void Autonomous::StartAutonomousFromGameData()
{
	Side	nearSwitchSide;
//	Side	scaleSide;
	// Side	opponentSwitchSide;
	// Add code to read switch/scale state from Field Management System
	// https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details
	auto gameData{frc::DriverStation::GetInstance().GetGameSpecificMessage()};
	if (gameData.size() < 3)
	{
		std::cout << "AutonomousInit - No game data.\n";
		return;
	}

	m_foundGameData = true;

	if (gameData[0] == 'L')
	{
		nearSwitchSide = Side::Left;
	}
	else
	{
		nearSwitchSide = Side::Right;
	}

//	if (gameData[1] == 'L')
//	{
//		scaleSide = Side::Left;
//	}
//	else
//	{
//		scaleSide = Side::Right;
//	}

/*	if (gameData[2] == 'L')
	{
		opponentSwitchSide = Side::Left;
	}
	else
	{
		opponentSwitchSide = Side::Right;
	} */

	switch(m_chooser.GetSelected())
	{
	case AutoCommand::Default:
		m_autonomousCommand = std::make_unique<DriveStraightCommand>(2.0);
		break;
	case AutoCommand::PlaceInitialCubeOnSwitch:
		m_autonomousCommand = std::make_unique<PlaceInitialCubeOnSwitchCommandGroup>(nearSwitchSide);
		break;
	case AutoCommand::PlaceCubeOnOurSide:
		m_autonomousCommand = std::make_unique<PlaceCubeOurSideOnlyCommandGroup>(nearSwitchSide);
		break;
	case AutoCommand::FromOutsideWallPlaceCubeOnOurSide:
		m_autonomousCommand = std::make_unique<FarLeftAndRightCommandGroup>(nearSwitchSide);
		break;
	}

	if (m_autonomousCommand)
	{
		std::cout << "Starting -- " << m_autonomousCommand->GetName() << '\n';
		m_autonomousCommand->Start();
	}
}
