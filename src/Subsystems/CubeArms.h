/*
 * CubeArms.h
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#ifndef CUBEARMS_H_
#define CUBEARMS_H_

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>

class CubeArms: public frc::Subsystem
{
private:
	// private members
	frc::DoubleSolenoid m_foldArms {0, 1};

public:
	CubeArms();
	virtual ~CubeArms();

	void FoldUp();
	void FoldDown();
};

#endif /* CUBEARMS_H_ */
