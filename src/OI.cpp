/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/RaiseHooksUpToRungCommand.h>
#include <Commands/DropHooksDownCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Commands/FoldArmsUpCommand.h>
#include <Commands/OpeningAndClosingArmsCommand.h>
#include <Commands/StopArmWheelsCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>

OI::OI()
{
	DriverJoystick.reset(new frc::Joystick(0));
	ButtonBox.reset(new frc::Joystick(1));

	RaiseHooksUpButton.reset(new frc::JoystickButton(ButtonBox.get(), 1));
	DropHooksDownButton.reset(new frc::JoystickButton(ButtonBox.get(), 2));
	StopArmWheelsButton.reset(new frc::JoystickButton(ButtonBox.get(), 3));
	FoldCubeArmsUpButton.reset(new frc::JoystickButton(ButtonBox.get(), 4));
	FoldCubeArmsDownButton.reset(new frc::JoystickButton(ButtonBox.get(), 5));
	SpinArmWheelsInButton.reset(new frc::JoystickButton(ButtonBox.get(), 6));
	OpeningAndClosingArmsButton.reset(new frc::JoystickButton(DriverJoystick.get(), 2));


	RaiseHooksUpButton->WhenPressed(new RaiseHooksUpToRungCommand());
	DropHooksDownButton->WhileHeld(new DropHooksDownCommand());
	StopArmWheelsButton->WhenPressed(new StopArmWheelsCommand());
	FoldCubeArmsUpButton->WhenPressed(new FoldArmsDownCommand());
	FoldCubeArmsDownButton->WhenPressed(new FoldArmsDownCommand());
	OpeningAndClosingArmsButton->WhenPressed(new OpeningAndClosingArmsCommand());

	// example how to put a command on the dashboard. You can press start and execute it.
	//frc::SmartDashboard::PutData("Raise Hooks Up", new RaiseHooksUpToRungCommand());
	frc::SmartDashboard::PutData("Move To to switch ", new MoveToVerticalCubePositionCommand(Switch));
	frc::SmartDashboard::PutData("Move To exchange ", new MoveToVerticalCubePositionCommand(Exchange));
	frc::SmartDashboard::PutData("Move To Level2 ", new MoveToVerticalCubePositionCommand(Level2));
	frc::SmartDashboard::PutData("Move To Level3 ", new MoveToVerticalCubePositionCommand(Level3));
	frc::SmartDashboard::PutData("Move To Portal ", new MoveToVerticalCubePositionCommand(Portal));

}

std::shared_ptr<frc::Joystick> OI::GetDriverJoystick()
{
	return DriverJoystick;
}

std::shared_ptr<frc::Joystick> OI::GetButtonBox()
{
	return ButtonBox;
}
