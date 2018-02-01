/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

// Create the unique static pointers for each subsystem
std::unique_ptr<DriveTrain> Robot::DriveTrainSubsystem;
std::unique_ptr<CubeArms> Robot::CubeArmsSubsystem;
std::unique_ptr<Climb> Robot::ClimbSubsystem;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit()
{
	// Initialize subsystems!
	DriveTrainSubsystem.reset(new DriveTrain());
	CubeArmsSubsystem.reset(new CubeArms());
	ClimbSubsystem.reset(new Climb());

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	SmartDashboard::PutData(DriveTrainSubsystem.get());

	// After subsystem creations, now create autonomous commands
	m_defaultAuto.reset(new MyAutoCommand());
	m_driveStraightAuto.reset(new DriveStraightCommand(3.0));

	m_chooser.AddDefault("Default Auto", m_defaultAuto.get());
	m_chooser.AddObject("Drive Straight", m_driveStraightAuto.get());
	frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

	CameraServer::GetInstance()->StartAutomaticCapture();
}

/**
 * This function is called once each time the robot enters Disabled
 * mode.
 * You can use it to reset any subsystem information you want to clear
 * when
 * the robot is disabled.
 */
void Robot::DisabledInit()
{
}

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to
 * select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to
 * the
 * chooser code above (like the commented example) or additional
 * comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
	// Add code to read switch/scale state from Field Management System
	// https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/826278-2018-game-data-details

//	std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
//	if (autoSelected == "Drive Straight")
//	{
//		m_autonomousCommand = &m_driveStraightAuto;
//	}
//	else
//	{
//		m_autonomousCommand = &m_defaultAuto;
//	}

	m_autonomousCommand = m_chooser.GetSelected();

	if (m_autonomousCommand != nullptr)
	{
		m_autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
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

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
}

START_ROBOT_CLASS(Robot)
