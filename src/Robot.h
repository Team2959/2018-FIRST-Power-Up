/*
 * Robot.h
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <TimedRobot.h>
#include <memory>
#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>

#include <OI.h>
#include <Subsystems/DriveTrain.h>
#include <Subsystems/CubeArms.h>
#include <Subsystems/MotionTracking.h>

#include <Commands/DriveStraightCommand.h>
#include <Commands/MyAutoCommand.h>
#include <Subsystems/ScaleClimb.h>


class Robot : public frc::TimedRobot
{
public:
	// Add all subsystem definition here as static public variables
	static std::unique_ptr<DriveTrain> DriveTrainSubsystem;
	static std::unique_ptr<CubeArms> CubeArmsSubsystem;
	static std::unique_ptr<ScaleClimb> ClimbSubsystem;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<MotionTracking> MotionTrackingSubsystem;

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
	std::unique_ptr<MyAutoCommand> m_defaultAuto;
	std::unique_ptr<DriveStraightCommand> m_driveStraightAuto;
	frc::SendableChooser<frc::Command*> m_chooser;
};

#endif /* SRC_ROBOT_H_ */
