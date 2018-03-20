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
	virtual void Initialize() override;
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;

private:
	bool IsTapeVisible();

	double	m_DriveAngle;
	double	m_autonSpeed;
	bool	m_isFinished{ false };
};

#endif /* SRC_COMMANDS_AUTO_SLIDETOTAPEVISIBLECOMMAND_H_ */
