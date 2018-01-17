/*
 * Robot.h
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#pragma once

#include <TimedRobot.h>
#include <memory>
#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <OI.h>
#include <Subsystems/DriveTrain.h>

class Robot : public frc::TimedRobot
{
public:
	// Add all subsystem definition here as static public variables
	static std::unique_ptr<DriveTrain> DriveTrainSubsystem;
	static std::unique_ptr<OI> oi;

public:
	void RobotInit() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	void AutonomousInit() override;
	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void TestPeriodic() override;

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	//ExampleCommand m_defaultAuto;
	//MyAutoCommand m_myAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
};
