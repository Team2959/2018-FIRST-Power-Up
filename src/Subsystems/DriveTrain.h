/*
 * DriveTrain.h
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#ifndef SRC_DRIVE_TRAIN_H_
#define SRC_DRIVE_TRAIN_H_

#include <Commands/Subsystem.h>
#include <memory>
#include "Utilities/XDrive.h"

class DriveTrain: public frc::Subsystem
{
private:


public:
	DriveTrain();
	~DriveTrain() override = default;
	std::shared_ptr<XDrive> m_xDrive;


	void InitDefaultCommand() override;

	// Drive robot via XDrive
	// Magnitude is 0 .. 1 for how fast to move
	// Total Angle is 0 .. 2 * Pi in radians for direction
	// Rotation is -1 .. 1
	void Drive(double magnitude, double totalAngle, double rotation);
};

#endif /* SRC_DRIVE_TRAIN_H_ */
