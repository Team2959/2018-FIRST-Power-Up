/*
 * TwoWheelRotateCommand.h
 *
 *  Created on: Mar 17, 2018
 *      Author: jcopi
 */

#ifndef SRC_COMMANDS_AUTO_TWOWHEELROTATECOMMAND_H_
#define SRC_COMMANDS_AUTO_TWOWHEELROTATECOMMAND_H_

#include <Commands/Command.h>

class TwoWheelRotateCommand: public frc::Command {
private:


public:
	TwoWheelRotateCommand();
	virtual ~TwoWheelRotateCommand();

	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_AUTO_TWOWHEELROTATECOMMAND_H_ */
