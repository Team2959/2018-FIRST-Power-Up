/*
 * DeliverCubeUntilNotPresentCommand.h
 *
 *  Created on: Mar 19, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_DELIVERCUBEUNTILNOTPRESENTCOMMAND_H_
#define SRC_COMMANDS_AUTO_DELIVERCUBEUNTILNOTPRESENTCOMMAND_H_

#include <Commands/Command.h>

class DeliverCubeUntilNotPresentCommand: public frc::Command
{
public:
	DeliverCubeUntilNotPresentCommand();
	virtual void Initialize() override;
	virtual void Execute() override;
	virtual void End() override;
	virtual void Interrupted() override;
	virtual bool IsFinished() override;

private:
	int	m_cubeNotpresentCount{ 0 };
};

#endif /* SRC_COMMANDS_AUTO_DELIVERCUBEUNTILNOTPRESENTCOMMAND_H_ */
