/*
 * SignalRegistration.h
 *
 *  Created on: Feb 10, 2018
 *      Author: JWB
 */

#include <csignal>

#ifndef SRC_SIGNAL_REGISTRATION_H_
#define SRC_SIGNAL_REGISTRATION_H_

class SignalRegistration
{
public:
	SignalRegistration(int signal, __sighandler_t handler);
	virtual ~SignalRegistration();

private:
	__sighandler_t	_oldHandler;	// The handler we replaced
	int				_signal;		// Our signal number
};

#endif /* SRC_SIGNAL_REGISTRATION_H_ */
