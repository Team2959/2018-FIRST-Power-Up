/*
 * Climb.h
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_SCALECLIMB_H_
#define SRC_SUBSYSTEMS_SCALECLIMB_H_

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <DigitalInput.h>

class ScaleClimb: public frc::Subsystem
{
private:
	frc::Spark m_leftSpark;
	frc::Spark m_rightSpark;
	frc::DigitalInput m_topLimitSwitch;
	frc::DigitalInput m_bottomLimitSwitch;

public:
	ScaleClimb();
	~ScaleClimb() override = default;

	void RaiseHooksUp();
	void DropHooksDown();
	void StopHooks();

	bool AtTop();
	bool AtBottom();
};

#endif /* SRC_SUBSYSTEMS_SCALECLIMB_H_ */
