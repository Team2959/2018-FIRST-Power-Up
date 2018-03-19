/*
 * TwoWheelDriveCommand.h
 *
 *  Created on: Mar 17, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_TWOWHEELDRIVECOMMAND_H_
#define SRC_COMMANDS_AUTO_TWOWHEELDRIVECOMMAND_H_

#include <Commands/Command.h>

constexpr double TWO_WHL_RAMP_DIST = 3;          // The distance over which to ramp speed
constexpr double TWO_WHL_FULL_TURN_DIFF = 2;     // The amount of feet the wheel displacements would differ by the necessitate full turn correct
constexpr double TWO_WHL_FULL_TURN_SPEED = 0.25; // The max speed of rotation correction
constexpr double TWO_WHL_LOW_RAMP_SPEED = 0.25;  // The starting speed for ramping
constexpr double TWO_WHL_MAX_ACCEPT_ROT = 0.5;   // Maximum distance of wheel difference before correction

class TwoWheelDriveCommand: public frc::Command
{

private:
	double m_speed;
	double m_origSpeed;
	double m_dist;
	double m_startDist;
	double m_wheelDiff;
	double m_disp;
	const char* m_motor1;
	const char* m_motor2;


public:
	TwoWheelDriveCommand(double dist, double speed, bool FrontLeftBackRight);
	virtual ~TwoWheelDriveCommand();

	void Initialize();
	void Execute();
	void End();
	void Interrupted();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_AUTO_TWOWHEELDRIVECOMMAND_H_ */
