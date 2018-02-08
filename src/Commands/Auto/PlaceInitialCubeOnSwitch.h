/*
 * PlaceInitialCubeOnSwitch.h
 *
 *  Created on: Feb 7, 2018
 *      Author: JWB
 */

#ifndef SRC_PLACE_INITIAL_CUBE_ON_SWITCH_H_
#define SRC_PLACE_INITIAL_CUBE_ON_SWITCH_H_

#include <Commands/CommandGroup.h>

class PlaceInitialCubeOnSwitchCommand : public frc::Command
{
public:
	PlaceInitialCubeOnSwitchCommand();
	~PlaceInitialCubeOnSwitchCommand() override = default;

protected:
	virtual void Execute() override;
	virtual void Initialize() override;
	virtual void Interrupted() override;
	virtual bool IsFinished() override;

private:
	frc::CommandGroup	_commands;
};

#endif /* SRC_PLACE_INITIAL_CUBE_ON_SWITCH_H_ */

