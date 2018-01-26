/*
 * CubeOnSwitchCommand.h
 *
 *  Created on: Jan 25, 2018
 *      Author: Tracy
 */

#pragma once

#include <Commands/Command.h>

class CubeOnSwitchCommand: public frc::Command
{
public:
	CubeOnSwitchCommand();
	~CubeOnSwitchCommand() override = default;

	bool IsFinished() override;
};
