/*
 * Robot.h
 *
 *  Created on: Jan 15, 2018
 *      Author:
 */

#pragma once

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>
#include <OI.h>
#include <memory>

class Robot : public frc::TimedRobot
{
public:
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

