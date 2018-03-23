/*
 * FCDeadReckoning.h
 *
 *  Created on: Mar 10, 2018
 *      Author: jcopi
 */

#ifndef SRC_COMMANDS_AUTO_FCDEADRECKONINGCOMMAND_H_
#define SRC_COMMANDS_AUTO_FCDEADRECKONINGCOMMAND_H_

#include <Commands/TimedCommand.h>
#include "RobotMap.h"
#include "Robot.h"

class FCDeadReckoningCommand: public frc::TimedCommand {
public:
	FCDeadReckoningCommand(double duration, double magnitude, double angle, double rotation);

	virtual void Initialize() override;
	virtual void Execute() override;
	virtual void End() override;
	virtual void Interrupted() override;

private:
	double m_magnitude;
	double m_rotation;
	double m_angle;
};

#endif /* SRC_COMMANDS_AUTO_FCDEADRECKONINGCOMMAND_H_ */
