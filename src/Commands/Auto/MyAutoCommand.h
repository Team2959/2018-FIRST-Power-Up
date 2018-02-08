/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef SRC_MY_AUTO_COMMAND_H_
#define SRC_MY_AUTO_COMMAND_H_

#include <Commands/Command.h>

class MyAutoCommand : public frc::Command
{
public:
	MyAutoCommand();

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_MY_AUTO_COMMAND_H_ */
