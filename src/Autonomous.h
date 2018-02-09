/*
 * Autonomous.h
 *
 *  Created on: Feb 8, 2018
 *      Author: Kevin
 */

#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include "Commands/Auto/DriveStraightCommand.h"
#include "Commands/Auto/MyAutoCommand.h"
#include "Commands/Auto/PlaceInitialCubeOnSwitch.h"

class Autonomous
{
private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;

	frc::SendableChooser<frc::Command*> m_chooser;

	MyAutoCommand m_defaultAuto;
	DriveStraightCommand m_driveStraightAuto;
	PlaceInitialCubeOnSwitchCommand	m_placeInitialCubeOnSwitch;

public:
	Autonomous();
	virtual ~Autonomous();

	void AutoInit();
	void TeleopInit();
};

#endif /* SRC_AUTONOMOUS_H_ */
