/*
 * RotateRelitiveAngleCommand.h
 *
 *  Created on: Mar 17, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_ROTATERELATIVEANGLECOMMAND_H_
#define SRC_COMMANDS_AUTO_ROTATERELATIVEANGLECOMMAND_H_

#include <Commands/Command.h>

class RotateRelativeAngleCommand: public frc::Command
{
private:
	static constexpr double	Acceleration{0.5};
	double 	m_targetAngle;
	double 	m_startAngle;
	double 	m_speed;
	double	m_lastSpeed;
	double 	m_readingOffset;
	bool 	m_atTarget;

public:
	RotateRelativeAngleCommand();

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_AUTO_ROTATERELATIVEANGLECOMMAND_H_ */
