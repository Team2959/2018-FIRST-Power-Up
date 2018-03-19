/*
 * DeliverCubeUntilNotPresentCommand.h
 *
 *  Created on: Mar 19, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_DELIVERCUBEUNTILNOTPRESENTCOMMAND_H_
#define SRC_COMMANDS_AUTO_DELIVERCUBEUNTILNOTPRESENTCOMMAND_H_

#include <Commands/Command.h>

class DeliverCubeUntilNotPresentCommand: public frc::Command {
public:
	DeliverCubeUntilNotPresentCommand();
	virtual ~DeliverCubeUntilNotPresentCommand();

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;
	bool IsFinished() override;

private:
	int m_cubeNotpresentCount;
};

#endif /* SRC_COMMANDS_AUTO_DELIVERCUBEUNTILNOTPRESENTCOMMAND_H_ */
