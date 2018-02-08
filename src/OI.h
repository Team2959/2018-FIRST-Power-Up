/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef SRC_OI_H_
#define SRC_OI_H_

#include <memory>
#include <Joystick.h>
#include <Buttons/JoystickButton.h>

class OI
{
private:
	std::shared_ptr<frc::Joystick> DriverJoystick;
	std::shared_ptr<frc::Joystick> ButtonBox;

	std::shared_ptr<frc::JoystickButton> RaiseHooksUpButton;
	std::shared_ptr<frc::JoystickButton> DropHooksDownButton;
	std::shared_ptr<frc::JoystickButton> StopArmWheelsButton;
	std::shared_ptr<frc::JoystickButton> FoldCubeArmsUpButton;
	std::shared_ptr<frc::JoystickButton> FoldCubeArmsDownButton;
	std::shared_ptr<frc::JoystickButton> SpinArmWheelsInButton;
	std::shared_ptr<frc::JoystickButton> OpeningAndClosingArmsButton;

public:
	OI();

	std::shared_ptr<frc::Joystick> GetDriverJoystick();
	std::shared_ptr<frc::Joystick> GetButtonBox();
};

#endif /* SRC_OI_H_ */
