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
#include "OI.h"
#include "Utilities/XDrive.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/CubeArms.h"
#include "Subsystems/MotionTracking.h"
#include "Subsystems/ScaleClimb.h"
#include "Subsystems/CubeDelivery.h"
#include "Subsystems/Vision.h"
#include <Autonomous.h>
#include <Subsystems/VerticalArmMovement.h>
#include <PowerDistributionPanel.h>

class Robot : public frc::TimedRobot
{
private:
	std::shared_ptr<XDrive> m_xDrive;
	std::unique_ptr<Autonomous> m_autonomous;
	unsigned int periodicCount;

	frc::PowerDistributionPanel m_pdp {0};

public:
	// Add all subsystem definition here as static public variables
	static std::unique_ptr<DriveTrain> DriveTrainSubsystem;
	static std::unique_ptr<CubeArms> CubeArmsSubsystem;
	static std::unique_ptr<ScaleClimb> ClimbSubsystem;
	static std::unique_ptr<CubeDelivery> CubeDeliverySubsystem;
	static std::unique_ptr<MotionTracking> MotionTrackingSubsystem;
	static std::unique_ptr<VerticalArmMovement> VerticalArmMovmentSubsystem;
	static std::unique_ptr<Vision> VisionSubsystem;

	// OI last
	static std::unique_ptr<OI> oi;

public:
	void RobotInit() override;
	void RobotPeriodic() override;

	void DisabledInit() override;
	void DisabledPeriodic() override;

	void AutonomousInit() override;
	void AutonomousPeriodic() override;

	void TeleopInit() override;
	void TeleopPeriodic() override;

	void TestPeriodic() override;

	virtual void StartCompetition() override;

private:
	static void SignalHandler(int signal);	// Handle a signal from the operating system
	void TestPixyCam();
};

#endif /* SRC_ROBOT_H_ */
