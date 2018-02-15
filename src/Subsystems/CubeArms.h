/*
 * CubeArms.h
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#ifndef SRC_CUBE_ARMS_H_
#define SRC_CUBE_ARMS_H_

#include <Commands/Subsystem.h>
#include <Solenoid.h>

class CubeArms: public frc::Subsystem
{
private:
	frc::Solenoid m_foldArms;

public:
	CubeArms();
	~CubeArms() override = default;

	void FoldUp();
	void FoldDown();
};

#endif /* SRC_CUBE_ARMS_H_ */
