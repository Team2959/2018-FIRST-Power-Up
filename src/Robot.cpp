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
	// Initialize before subsystems, since needed there!
	m_xDrive.reset(new XDrive());

	// Initialize subsystems!
	DriveTrainSubsystem.reset(new DriveTrain(m_xDrive));
	MotionTrackingSubsystem.reset(new MotionTracking(m_xDrive));
	CubeArmsSubsystem.reset(new CubeArms());
	ClimbSubsystem.reset(new ScaleClimb());
	CubeDeliverySubsystem.reset(new CubeDelivery());
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
//	SmartDashboard::PutData(CubeDeliverySubsystem.get());
//	frc::SmartDashboard::PutData(&m_pdp);

//	cs::UsbCamera cam = CameraServer::GetInstance()->StartAutomaticCapture();
//	cam.SetResolution(320,240);

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

static decltype(std::chrono::high_resolution_clock::now())	startTime;

static void ResetStartTime()
{
	startTime = std::chrono::high_resolution_clock::now();
}

/*
static double ElapsedMS()
{
	return (std::chrono::high_resolution_clock::now() - startTime).count() / 1000000.0;
}

static double lastAccelerationX = 0.0;
static double lastAccelerationY = 0.0;
static double lastAccelerationZ = 0.0;
static double lastVelocityX = 0.0;
static double lastVelocityY = 0.0;
static double lastVelocityZ = 0.0;
static double lastDisplacementX = 0.0;
static double lastDisplacementY = 0.0;
static double lastDisplacementZ = 0.0;
static frc::BuiltInAccelerometer	bia;
static long lastSensorTimestamp = 0; */

void Robot::RobotPeriodic()
{
	auto&	navX{ *MotionTrackingSubsystem->m_navmxp };
	if(periodicCount == 0)
	{
		ResetStartTime();
/*		auto	accelerationX{ navX.GetRawAccelX() };
		auto	accelerationY{ navX.GetRawAccelY() };
		navX.UpdateDisplacement(accelerationX, accelerationY,50,false); */

		std::cout << navX.GetQuaternionX() << ',' <<
				     navX.GetQuaternionY() << ',' <<
					 navX.GetQuaternionY() << ',' <<
					 navX.GetQuaternionZ() << '\n';
		navX.Reset();
		navX.ResetDisplacement();
		navX.ZeroYaw();
		std::cout << navX.GetQuaternionX() << ',' <<
				     navX.GetQuaternionY() << ',' <<
					 navX.GetQuaternionY() << ',' <<
					 navX.GetQuaternionZ() << '\n';
	}

	if ((periodicCount % 5) == 0)
	{
		CubeDeliverySubsystem->UpdateSmartDashboard();
		ClimbSubsystem->UpdateSmartDashboard();
		VerticalArmMovmentSubsystem->UpdateSmartDashboard();
		MotionTrackingSubsystem->SendMotorNumberToDash();
	}

//	if ((periodicCount % 5) == 0)
//	{
//		MotionTrackingSubsystem->PrintMotorTelemetries();
		/*std::cout << navX.GetYaw() << ',' <<
					navX.GetPitch() << ',' <<
					navX.GetRoll() << ',' <<
					 navX.GetRawGyroX() << ','<<
					 navX.GetRawGyroY() << ','<<
					 navX.GetRawGyroZ() << '\n';*/
		/* std::cout << "**" << navX.GetQuaternionX() << ',' <<
				     navX.GetQuaternionY() << ',' <<
					 navX.GetQuaternionY() << ',' <<
					 navX.GetQuaternionZ() << '\n'; */
//	}

/*	if(MotionTrackingSubsystem.get() != nullptr)
	{
		static unsigned indexNumber{0};
		auto	time { ElapsedMS() };
		auto 	angle{ navX.GetAngle() };
		auto	isCalibrating{ navX.IsCalibrating() };

		auto	accelerationX{ 9.8 * bia.GetX() };
		auto	accelerationY{ 9.8 * bia.GetY() };
		auto	accelerationZ{ 9.8 * bia.GetZ() };
		auto	sensorTimestamp{navX.GetLastSensorTimestamp()};
//		auto 	updateRate((int)(1.0 / timeDifference + 0.5));
		auto	isMoving{ navX.IsMoving() };

		long	timeDifferenceMs;

		if(isCalibrating)
		{
			lastSensorTimestamp = 0;
			timeDifferenceMs = 0;
		}
		else if(lastSensorTimestamp == 0)
		{
			lastSensorTimestamp = sensorTimestamp;
			timeDifferenceMs = 0;
		}
		else
		{
			timeDifferenceMs = sensorTimestamp - lastSensorTimestamp;
			lastSensorTimestamp = sensorTimestamp;
		}

		auto	timeDifferenceSec{ timeDifferenceMs / 1000.0};



		double	accelerationX;
		double	accelerationY;
		double	accelerationZ;
		double	velocityX;
		double	velocityY;
		// double	velocityZ;
		double	displacementX;
		double	displacementY;
		// double	displacementZ;



		if(timeDifferenceMs != 0)
		{
			accelerationX = 9.8 * navX.GetWorldLinearAccelX();
			accelerationY = 9.8 * navX.GetWorldLinearAccelY();
			accelerationZ = 9.8 * navX.GetWorldLinearAccelZ();
		}
		else
		{
			accelerationX = 0.0;
			accelerationY = 0.0;
			accelerationZ = 0.0;
		}

		auto	newVelocityX{ lastVelocityX + ((accelerationX + lastAccelerationX) / 2.0) * timeDifferenceSec };
		auto	newVelocityY{ lastVelocityY + ((accelerationY + lastAccelerationY) / 2.0) * timeDifferenceSec };
		auto	newVelocityZ{ lastVelocityZ + ((accelerationZ + lastAccelerationZ) / 2.0) * timeDifferenceSec };

		auto	newDisplacementX{ lastDisplacementX + ((lastVelocityX + newVelocityX) / 2.0) * timeDifferenceSec };
		auto	newDisplacementY{ lastDisplacementY + ((lastVelocityY + newVelocityY) / 2.0) * timeDifferenceSec };
		auto	newDisplacementZ{ lastDisplacementZ + ((lastVelocityZ + newVelocityZ) / 2.0) * timeDifferenceSec };

		lastAccelerationX = accelerationX;
		lastAccelerationY = accelerationY;
		lastAccelerationZ = accelerationZ;

		lastVelocityX = newVelocityX;
		lastVelocityY = newVelocityY;
		lastVelocityZ = newVelocityZ;

		lastDisplacementX = newDisplacementX;
		lastDisplacementY = newDisplacementY;
		lastDisplacementZ = newDisplacementZ;

		velocityX = newVelocityX;
		velocityY = newVelocityY;
		// velocityZ = newVelocityZ;

		displacementX = newDisplacementX;
		displacementY = newDisplacementY;
		// displacementZ = newDisplacementZ;

		auto velocity = sqrt(velocityX * velocityX + velocityY * velocityY);
		auto displacement = sqrt(displacementX * displacementX + displacementY * displacementY);


		if(!isMoving)
		{
			accelerationX = 0.0;
			accelerationY = 0.0;
			accelerationZ = 0.0;
			lastVelocityX = 0.0;
			lastVelocityY = 0.0;
			lastVelocityZ = 0.0;
		}

		// navX.UpdateDisplacement(accelerationX, accelerationY,updateRate,isMoving);


		auto	velocityX{ navX.GetVelocityX() };
		auto	velocityY{ navX.GetVelocityY() };
		auto	velocityZ{ navX.GetVelocityZ() };
		auto	displacementX{ navX.GetDisplacementX() };
		auto	displacementY{ navX.GetDisplacementY() };
		auto	displacementZ{ navX.GetDisplacementZ() };

		if(isMoving||isCalibrating||((periodicCount% 200) == 0))
		{
		while(angle >= 360.0)
			angle -= 360.0;
		while(angle < 0)
			angle += 360.0;
	std::cout << indexNumber++ << ',' <<
			time << ',' <<
			// timeDifferenceMs << ',' <<
			// isMoving << ',' <<
			// isCalibrating << ',' <<
			// angle * Pi / 180.0 << ',' <<
			accelerationX << ',' <<
			accelerationY << ',' <<
			accelerationZ << ',' <<
			velocityX << ',' <<
			velocityY << ',' <<
			velocityZ << ',' <<
			displacementX << ',' <<
			displacementY << ',' <<
			displacementZ << '\n';
			velocity << ',' << displacement << '\n';
		}
	}
*/
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

	if ((periodicCount % 100) == 0)
	{
		std::vector<VisionObject>	cubeVisionObjects = Robot::VisionSubsystem->GetObjects(CubeColor);
		frc::SmartDashboard::PutBoolean("Sees Cube(s)", !cubeVisionObjects.empty());

//		std::vector<VisionObject>	tapeVisionObjects = Robot::VisionSubsystem->GetObjects(TapeColor);
//		frc::SmartDashboard::PutBoolean("Sees Tape(s)", !tapeVisionObjects.empty());
	}
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
