/*
 * CubeArms.h
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#pragma once

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>

class CubeArms: public frc::Subsystem
{
private:
	// private members
	frc::DoubleSolenoid m_foldArms {0, 1};

public:
	CubeArms();
	~CubeArms() override = default;

	void FoldUp();
	void FoldDown();
};
