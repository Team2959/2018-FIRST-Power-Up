/*
 * SlideToTapeVisibleCommand.h
 *
 *  Created on: Mar 6, 2018
 *      Author: Aria
 */

#ifndef SRC_COMMANDS_AUTO_SLIDETOTAPEVISIBLECOMMAND_H_
#define SRC_COMMANDS_AUTO_SLIDETOTAPEVISIBLECOMMAND_H_

#include <Commands/Command.h>
#include "../../Autonomous.h"

class SlideToTapeVisibleCommand: public frc::Command
{
public:
	SlideToTapeVisibleCommand(Side nearSwitchSide);
	~SlideToTapeVisibleCommand() override = default;

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_AUTO_SLIDETOTAPEVISIBLECOMMAND_H_ */
