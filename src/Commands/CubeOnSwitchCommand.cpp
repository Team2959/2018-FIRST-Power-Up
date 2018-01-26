/*
 * CubeOnSwitchCommand.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: Andrew
 */

#include <Commands/CubeOnSwitchCommand.h>

CubeOnSwitchCommand::CubeOnSwitchCommand() : Command("CubeOnSwitchCommand")
{
}

bool CubeOnSwitchCommand::IsFinished()
{
	return false;
}
