/*
 * Climb.h
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_SCALECLIMB_H_
#define SRC_SUBSYSTEMS_SCALECLIMB_H_

#include <Commands/Subsystem.h>
#include <memory>
#include <Spark.h>
#include <DigitalInput.h>

class ScaleClimb: public frc::Subsystem
{
private:
	std::shared_ptr<frc::Spark> m_leftSpark;
	std::shared_ptr<frc::Spark> m_rightSpark;
	std::shared_ptr<frc::DigitalInput> m_topLimitSwitch;

public:
	ScaleClimb();
	~ScaleClimb() override = default;

	void RaiseHooksUp();
	void DropHooksDown();
	void StopHooks();

	bool AtTop();
};

#endif /* SRC_SUBSYSTEMS_SCALECLIMB_H_ */
