/*
 * TwoWheelDriveCommand.h
 *
 *  Created on: Mar 17, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_TWOWHEELDRIVECOMMAND_H_
#define SRC_COMMANDS_AUTO_TWOWHEELDRIVECOMMAND_H_

#include <Commands/Command.h>

class TwoWheelDriveCommand: public frc::Command
{
public:
	TwoWheelDriveCommand(double dist, double speed, bool frontLeftBackRight);

	virtual void Initialize() override;
	virtual void Execute() override;
	virtual void End() override;
	virtual void Interrupted() override;
	virtual bool IsFinished() override;

private:
	static constexpr double TWO_WHL_RAMP_DIST = 3;          // The distance over which to ramp speed
	static constexpr double TWO_WHL_FULL_TURN_DIFF = 2;     // The amount of feet the wheel displacements would differ by the necessitate full turn correct
	static constexpr double TWO_WHL_FULL_TURN_SPEED = 0.25; // The max speed of rotation correction
	static constexpr double TWO_WHL_LOW_RAMP_SPEED = 0.25;  // The starting speed for ramping
	static constexpr double TWO_WHL_MAX_ACCEPT_ROT = 200;   // Maximum distance of wheel difference before correction

	double 		m_disp{ 0.0 };
	double 		m_wheelDiff{ 0.0 };
	double 		m_dist;
	double 		m_speed;
	double 		m_startDist;
	double		m_driveAngle;
	const char* m_motor1;
	const char* m_motor2;
	double m_startAngle;
};

#endif /* SRC_COMMANDS_AUTO_TWOWHEELDRIVECOMMAND_H_ */
