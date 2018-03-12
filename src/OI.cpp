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
#include <Commands/StopArmWheelsCommand.h>
#include <Commands/SpinArmWheelsInCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/DeliverCubeCommand.h>
#include <Commands/MoveToAbsoluteHeightCommand.h>
#include <Commands/OpenOrCloseCubeArmsCommand.h>
#include <Commands/StopVerticalCommand.h>

OI::OI()
{
	// Create USB joysticks
	DriverJoystick.reset(new frc::Joystick(0));
	ButtonBox.reset(new frc::Joystick(1));

	// map driver buttons
	OpenOrCloseCubeArmsButton.reset(new frc::JoystickButton(DriverJoystick.get(), 2));

	// map co-pilot buttons
	StopArmWheelsButton.reset(new frc::JoystickButton(ButtonBox.get(), 1));
	SpinArmWheelsInButton.reset(new frc::JoystickButton(ButtonBox.get(), 2));
	RaiseHooksUpButton.reset(new frc::JoystickButton(ButtonBox.get(), 3));
	DropHooksDownButton.reset(new frc::JoystickButton(ButtonBox.get(), 4));
	FoldCubeArmsDownButton.reset(new frc::JoystickButton(ButtonBox.get(), 5));
	FoldCubeArmsUpButton.reset(new frc::JoystickButton(ButtonBox.get(), 6));
//	VerticalActivateButton.reset(new frc::JoystickButton(ButtonBox.get(), 7));
	DeliverCubeButton.reset(new frc::JoystickButton(ButtonBox.get(), 8));

	// Triggers
	IsCubePresentTrigger.reset(new CubePresentTrigger());
	AtBottomTrigger.reset(new VerticalBottomTrigger());

	// Tie buttons to commands
	OpenOrCloseCubeArmsButton->WhenPressed(new OpenOrCloseCubeArmsCommand());
	RaiseHooksUpButton->WhenPressed(new RaiseHooksUpToRungCommand());
	DropHooksDownButton->WhileHeld(new DropHooksDownCommand());
	StopArmWheelsButton->WhenPressed(new StopArmWheelsCommand());
	FoldCubeArmsUpButton->WhenPressed(new FoldArmsUpCommand());
	FoldCubeArmsDownButton->WhenPressed(new FoldArmsDownCommand());
	SpinArmWheelsInButton->WhenPressed(new SpinArmWheelsInCommand());
	DeliverCubeButton->WhenPressed(new DeliverCubeCommand());

	IsCubePresentTrigger->WhenActive(new StopArmWheelsCommand(0.5));
	AtBottomTrigger->WhenActive(new StopVerticalCommand());

	// example how to put a command on the dashboard. You can press start and execute it.
	//frc::SmartDashboard::PutData("Raise Hooks Up", new RaiseHooksUpToRungCommand());
	frc::SmartDashboard::PutData("Move To to switch ", new MoveToVerticalCubePositionCommand(VerticalArmMovement::Switch));
	frc::SmartDashboard::PutData("Move To Level1 ", new MoveToVerticalCubePositionCommand(VerticalArmMovement::Level1));
	frc::SmartDashboard::PutData("Move To exchange ", new MoveToVerticalCubePositionCommand(VerticalArmMovement::Exchange));
	frc::SmartDashboard::PutData("Move To Level2 ", new MoveToVerticalCubePositionCommand(VerticalArmMovement::Level2));
	frc::SmartDashboard::PutData("Move To Level3 ", new MoveToVerticalCubePositionCommand(VerticalArmMovement::Level3));
	frc::SmartDashboard::PutData("Move To Portal ", new MoveToVerticalCubePositionCommand(VerticalArmMovement::Portal));
	frc::SmartDashboard::PutNumber("Absolute Position", 0);
	frc::SmartDashboard::PutData("Move To Absolute Height ", new MoveToAbsoluteHeightCommand());
}

std::shared_ptr<frc::Joystick> OI::GetDriverJoystick()
{
	return DriverJoystick;
}

std::shared_ptr<frc::Joystick> OI::GetButtonBox()
{
	return ButtonBox;
}
