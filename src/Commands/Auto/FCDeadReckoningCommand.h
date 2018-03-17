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
	virtual ~FCDeadReckoningCommand();

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;

private:
	double m_magnitude;
	double m_rotation;
	double m_angle;
};

std::vector<std::string> strSplitLines(std::string str);

#endif /* SRC_COMMANDS_AUTO_FCDEADRECKONINGCOMMAND_H_ */
