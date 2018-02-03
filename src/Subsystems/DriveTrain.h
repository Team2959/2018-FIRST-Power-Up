/*
 * DriveTrain.h
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#pragma once

#include <Commands/Subsystem.h>
#include <memory>
#include "Utilities/XDrive.h"

class DriveTrain: public frc::Subsystem
{
private:
	std::shared_ptr<XDrive> m_xDrive;


public:
	DriveTrain();
	~DriveTrain() override = default;

	void InitDefaultCommand() override;

	// Drive robot via XDrive
	// Magnitude is 0 .. 1 for how fast to move
	// Total Angle is 0 .. 2 * Pi in radians for direction
	// Rotation is -1 .. 1
	void Drive(double magnitude, double totalAngle, double rotation);

};
