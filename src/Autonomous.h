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

class Autonomous
{
private:
	// The chooser seems problematic updating the SmartDashboard when it uses an frc::Command* as its stored data.
	// So, use an enum, and map from that enum to our command.

	enum class AutoCommand
	{
		Default,
		DriveStraight,
		PlaceInitialCubeOnSwitch
	};

	frc::SendableChooser<AutoCommand>	m_chooser;
	std::unique_ptr<frc::Command>		m_autonomousCommand;

public:
	Autonomous();

	void AutoInit();
	void TeleopInit();
};

#endif /* SRC_AUTONOMOUS_H_ */
