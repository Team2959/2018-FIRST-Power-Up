/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <csignal>
#include <cstring>
#include <iostream>
#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include <CameraServer.h>
#include "PixyCam/Camera.h"
#include "PixyCam/I2CChannel.h"
#include "SignalRegistration.h"
#include <PowerDistributionPanel.h>


// Create the unique static pointers for each subsystem
std::unique_ptr<DriveTrain> Robot::DriveTrainSubsystem;
std::unique_ptr<CubeArms> Robot::CubeArmsSubsystem;
std::unique_ptr<ScaleClimb> Robot::ClimbSubsystem;
std::unique_ptr<CubeDelivery> Robot::CubeDeliverySubsystem;
std::unique_ptr<MotionTracking> Robot::MotionTrackingSubsystem;
std::unique_ptr<VerticalArmMovement> Robot::VerticalArmMovmentSubsystem;
std::unique_ptr<Vision> Robot::VisionSubsystem;

std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit()
{
	m_xDrive.reset(new XDrive());

	// Initialize subsystems!
	DriveTrainSubsystem.reset(new DriveTrain(m_xDrive));
	CubeArmsSubsystem.reset(new CubeArms());
	ClimbSubsystem.reset(new ScaleClimb());
	CubeDeliverySubsystem.reset(new CubeDelivery());
	MotionTrackingSubsystem.reset(new MotionTracking(m_xDrive));
	VerticalArmMovmentSubsystem.reset(new VerticalArmMovement());
	VisionSubsystem = std::make_unique<Vision>();

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	m_autonomous.reset(new Autonomous());

//	SmartDashboard::PutData(DriveTrainSubsystem.get());
//	SmartDashboard::PutData(CubeArmsSubsystem.get());
//	SmartDashboard::PutData(ClimbSubsystem.get());
	SmartDashboard::PutData(CubeDeliverySubsystem.get());
//	frc::SmartDashboard::PutData(&m_pdp);

//	CameraServer::GetInstance()->StartAutomaticCapture();

	periodicCount = 0;
}

// Handler for C library signals
void Robot::SignalHandler(int signal) { std::cout << "C SIGNAL! - " << strsignal(signal) << '\n'; }

// We have had some instances where the robot restarts user application repeatedly.
// This is here to give us a hint for any possible information that might help
// narrow down the problem
void Robot::StartCompetition()
{
	// These registrations take care of registering/unregistring for C signal handling
	SignalRegistration	SIGILLReg{SIGILL, SignalHandler};
	SignalRegistration	SIGBUSReg{SIGBUS, SignalHandler};
	SignalRegistration	SIGSEGVReg{SIGSEGV, SignalHandler};

	// Call the base function inside our try/catch block
	try
	{
		frc::TimedRobot::StartCompetition();
	}
	catch(std::exception& e)							// All STL exceptions (and any well designed exceptions) should be caught here
	{
		std::cout << "EXCEPTION! - " << e.what() << '\n';
	}
	catch(...)											// All other exceptions should be caught here.
	{
		std::cout << "UNKNOWN EXCEPTION DETECTED!\n";	// We don't know anything about it, but we know it happend
	}

	// Our SignalRegistrations will now go out of scope, unregistering their handlers
}

void Robot::RobotPeriodic()
{
	if ((periodicCount % 5) == 0)
	{
		CubeDeliverySubsystem->UpdateSmartDashboard();
		ClimbSubsystem->UpdateSmartDashboard();
		VerticalArmMovmentSubsystem->UpdateSmartDashboard();
	}

	if ((periodicCount % 100) == 0)
	{
		//MotionTrackingSubsystem->PrintMotorTelemetries();
	}

	++periodicCount;
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
	MotionTrackingSubsystem->ResetTelemetries();
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
	m_autonomous->AutoInit();
}

void Robot::AutonomousPeriodic()
{
	m_autonomous->AutoPeriodic();
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	m_autonomous->CancelAutonomousCommand();
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	VisionSubsystem->TestPixyCam();
	frc::TimedRobot::TestPeriodic();
}

START_ROBOT_CLASS(Robot)
