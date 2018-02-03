/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <SmartDashboard/SmartDashboard.h>
//#include "Commands/TestPixyCam.h"
#include <Commands/RaiseHooksUpToRungCommand.h>
#include <Commands/DropHooksDownCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Commands/FoldArmsUpCommand.h>

OI::OI()
{
	DriverJoystick.reset(new frc::Joystick(0));
	ButtonBox.reset(new frc::Joystick(1));

	RaiseHooksUpButton.reset(new frc::JoystickButton(ButtonBox.get(), 1));
	DropHooksDownButton.reset(new frc::JoystickButton(ButtonBox.get(), 2));
	FoldCubeArmsUpButton.reset(new frc::JoystickButton(ButtonBox.get(), 4));
	FoldCubeArmsDownButton.reset(new frc::JoystickButton(ButtonBox.get(), 5));

	RaiseHooksUpButton->WhenPressed(new RaiseHooksUpToRungCommand());
	DropHooksDownButton->WhileHeld(new DropHooksDownCommand());
	FoldCubeArmsUpButton->WhenPressed(new FoldArmsDownCommand());
	FoldCubeArmsDownButton->WhenPressed(new FoldArmsDownCommand());

	//frc::SmartDashboard::PutData("Pixy Cam", new TestPixyCam());
}

std::shared_ptr<frc::Joystick> OI::GetDriverJoystick()
{
	return DriverJoystick;
}
