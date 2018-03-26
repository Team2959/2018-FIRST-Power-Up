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
#include <Commands/Auto/DeadReckoningCenterCommandGroup.h>
#include <Commands/Auto/RotateRelativeAngleCommand.h>
#include <Commands/Auto/FCDRChainCommandGroup.h>
#include <Commands/Auto/TwoWheelDriveCommand.h>
#include <Commands/Auto/TwCenterAutoCommandGroup.h>
#include <Commands/Auto/TwSwitchCubeScaleCommandGroup.h>
#include <Commands/Auto/TwScaleOnlyCommandGroup.h>

Autonomous::Autonomous()
{
	m_chooser.AddDefault("Drive Straight", AutoCommand::Default);
//	m_chooser.AddObject("Center-Place Initial Cube On Switch", AutoCommand::PlaceInitialCubeOnSwitch);
//	m_chooser.AddObject("Left/Right-Place Cube On Our Side", AutoCommand::PlaceCubeOnOurSide);
//	m_chooser.AddObject("No Vision Center", AutoCommand::NoVisionCenter);
	m_chooser.AddObject("Two Wheel Straight", AutoCommand::AutonStraight);
	m_chooser.AddObject("Two Wheel Rotate", AutoCommand::AutonRotate);
	m_chooser.AddObject("ScriptAuton", AutoCommand::ScriptAuton);
	m_chooser.AddObject("TW: Lf/Rt : Switch and Scale", AutoCommand::TwoWheelSwitchCubeScale);
	m_chooser.AddObject("TW: Center: Switch and Scale", AutoCommand::TwoWheelSwitchCubeScaleFromCenter);
	m_chooser.AddObject("TW: Scale and Scale", AutoCommand::TwoWheelScaleCubeScale);
	m_chooser.AddObject("TW: Scale and Switch", AutoCommand::TwoWheelScaleCubeSwitch);
	m_chooser.AddObject("TW: Scale Only", AutoCommand::TwScaleOnlyCommandGroup);

	frc::SmartDashboard::PutData("Autonomous Command", &m_chooser);

	frc::SmartDashboard::PutNumber("Auton Speed", 1.0);
	frc::SmartDashboard::PutBoolean("Is Auton Starting Left?", true);

	// two wheel drive, encoder based
	frc::SmartDashboard::PutNumber("Auton Angle", 45.0);
	frc::SmartDashboard::PutNumber("Auton TW Dist", 10);
	frc::SmartDashboard::PutString("Auton Script", "");

	// more vision or dead reckoning based
	frc::SmartDashboard::PutNumber("Auton Shimmy Speed", 0.2);
	frc::SmartDashboard::PutNumber("Auton Straight To Switch Time", 1.0);
	frc::SmartDashboard::PutNumber("Auton Straight Time", 3.5);
	frc::SmartDashboard::PutNumber("Auton Center Time", 3.5);

	m_foundGameData = false;
	m_cycleCount = 0;
}

void Autonomous::AutoInit()
{
	m_foundGameData = false;
	m_cycleCount = 0;
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
	Side	scaleSide;
	// Side	opponentSwitchSide;
	// Add code to read switch/scale state from Field Management System
	// https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details
	auto gameData{frc::DriverStation::GetInstance().GetGameSpecificMessage()};
	m_foundGameData = gameData.size() >= 3;
	if (!m_foundGameData)
	{
		m_cycleCount++;

		if (m_cycleCount < 50)
		{
			std::cout << "AutonomousInit - No game data.\n";
			return;
		}
	}

	if (!m_foundGameData)
	{
		m_autonomousCommand = std::make_unique<DriveStraightCommand>(3.5);
		m_autonomousCommand->Start();
		return;
	}


	if (gameData[0] == 'L')
	{
		nearSwitchSide = Side::Left;
	}
	else
	{
		nearSwitchSide = Side::Right;
	}

	if (gameData[1] == 'L')
	{
		scaleSide = Side::Left;
	}
	else
	{
		scaleSide = Side::Right;
	}

/*	if (gameData[2] == 'L')
	{
		opponentSwitchSide = Side::Left;
	}
	else
	{
		opponentSwitchSide = Side::Right;
	} */

	std::cout << "Autonomous::StartAutonomousFromGameData\n";
	double time = frc::SmartDashboard::GetNumber("Auton Straight Time", 4.0);
	double speed = frc::SmartDashboard::GetNumber("Auton Speed", 1.0);
	double distance = frc::SmartDashboard::GetNumber("Auton TW Dist", 10);
	bool startLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Left?", true);
	switch(m_chooser.GetSelected())
	{
	case AutoCommand::Default:
		m_autonomousCommand = std::make_unique<DriveStraightCommand>(time);
		break;
	case AutoCommand::PlaceInitialCubeOnSwitch:
		m_autonomousCommand = std::make_unique<PlaceInitialCubeOnSwitchCommandGroup>(nearSwitchSide);
		break;
	case AutoCommand::PlaceCubeOnOurSide:
		m_autonomousCommand = std::make_unique<PlaceCubeOurSideOnlyCommandGroup>(nearSwitchSide);
		break;
	case AutoCommand::NoVisionCenter:
		m_autonomousCommand = std::make_unique<DeadReckoningCenterCommandGroup>(nearSwitchSide);
		break;
	case AutoCommand::TwoWheelSwitchCubeScaleFromCenter:
		m_autonomousCommand = std::make_unique<TwCenterAutoCommandGroup>(nearSwitchSide, scaleSide);
		break;
	case AutoCommand::TwScaleOnlyCommandGroup:
			m_autonomousCommand = std::make_unique<TwScaleOnlyCommandGroup>(startLeft, scaleSide);
			break;
	case AutoCommand::TwoWheelSwitchCubeScale:
		m_autonomousCommand = std::make_unique<TwSwitchCubeScaleCommandGroup>(startLeft, nearSwitchSide, scaleSide);
		break;
	case AutoCommand::TwoWheelScaleCubeScale:
	case AutoCommand::TwoWheelScaleCubeSwitch:
	case AutoCommand::AutonStraight:
		m_autonomousCommand = std::make_unique<TwoWheelDriveCommand>(distance, speed, false);
		break;
	case AutoCommand::AutonRotate:
		m_autonomousCommand = std::make_unique<RotateRelativeAngleCommand>(frc::SmartDashboard::GetNumber("Auton Angle", 45.0) * Pi / 180.0, speed);
		break;
	case AutoCommand::ScriptAuton:
		m_autonomousCommand = std::make_unique<FCDRChainCommandGroup>(frc::SmartDashboard::GetString("Auton Script", ""));
		break;
	}

	if (m_autonomousCommand)
	{
		std::cout << "Starting -- " << m_autonomousCommand->GetName() << '\n';
		m_autonomousCommand->Start();
	}
}
