/*
 * Climb.h
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_CLIMB_H_
#define SRC_SUBSYSTEMS_CLIMB_H_

#include <Commands/Subsystem.h>
#include <memory>
#include <Spark.h>
#include <DigitalInput.h>

class Climb: public frc::Subsystem
{
private:
	std::shared_ptr<frc::Spark> m_leftSpark;
	std::shared_ptr<frc::Spark> m_rightSpark;
	std::shared_ptr<frc::DigitalInput> m_topLimitSwitch;

public:
	Climb();
	virtual ~Climb();
};

#endif /* SRC_SUBSYSTEMS_CLIMB_H_ */
