/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <iostream>
#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include <CameraServer.h>
#include "PixyCam/Camera.h"
#include "PixyCam/I2CChannel.h"

// Create the unique static pointers for each subsystem
std::unique_ptr<DriveTrain> Robot::DriveTrainSubsystem;
std::unique_ptr<CubeArms> Robot::CubeArmsSubsystem;
std::unique_ptr<ScaleClimb> Robot::ClimbSubsystem;
std::unique_ptr<CubeDelivery> Robot::CubeDeliverySubsystem;
std::unique_ptr<MotionTracking> Robot::MotionTrackingSubsystem;
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
//	SmartDashboard::PutData(CubeDeliverySubsystem.get());

	CameraServer::GetInstance()->StartAutomaticCapture();

	periodicCount = 0;
}

void Robot::RobotPeriodic()
{
	if ((periodicCount % 100) == 0)
	{
		MotionTrackingSubsystem->PrintMotorTelemetries();
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
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	m_autonomous->TeleopInit();
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic()
{
	TestPixyCam();
	frc::TimedRobot::TestPeriodic();
}

void Robot::TestPixyCam()
{
	static PixyCam::Camera	camera{std::make_unique<PixyCam::I2CChannel>(frc::I2C::kOnboard,0)};
	auto blocks{ camera.ReadFrameBlocks() };

	if(blocks.size() == 0)
		std::cout << "None\n";
	else
		for(auto i = 0U; i < blocks.size(); ++i)
		{
			auto& block{blocks[i]};
			std::cout << i << ":  " << block.X() << ',' << block.Y() << ',' << block.Width() << ',' << block.Height() << '\n';
		}
}

START_ROBOT_CLASS(Robot)
