/*
 * CubeArms.h
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#ifndef SRC_CUBE_ARMS_H_
#define SRC_CUBE_ARMS_H_

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include "RobotMap.h"

class CubeArms: public frc::Subsystem
{
private:
	// private members
	frc::DoubleSolenoid m_foldArms {FOLD_CUBE_ARMS_FORWARD_SOLENOID, FOLD_CUBE_ARMS_REVERSE_SOLENOID};

public:
	CubeArms();
	~CubeArms() override = default;

	void FoldUp();
	void FoldDown();
};

#endif /* SRC_CUBE_ARMS_H_ */
