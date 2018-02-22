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
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Vision.h"

enum class Side { Left, Right };

class Autonomous
{
private:
	// The chooser seems problematic updating the SmartDashboard when it uses an frc::Command* as its stored data.
	// So, use an enum, and map from that enum to our command.

	enum class AutoCommand
	{
		Default,
		DriveStraight,
		PlaceInitialCubeOnSwitch,
		PlaceCubeOnLeftSwitch
	};

	frc::SendableChooser<AutoCommand>	m_chooser;
	std::unique_ptr<frc::Command>		m_autonomousCommand;

public:
	Autonomous(DriveTrain& driveTrain, Vision& vision);

	void AutoInit();
	void TeleopInit();

private:
	DriveTrain&	m_driveTrain;
	Vision& 	m_vision;
};

#endif /* SRC_AUTONOMOUS_H_ */
