/*
 * SignalRegistration.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: JWB
 */

#include "SignalRegistration.h"

SignalRegistration::SignalRegistration(int signal, __sighandler_t handler) :
_oldHandler{std::signal(signal, handler)}, _signal{ signal } { }

SignalRegistration::~SignalRegistration() { std::signal(_signal, _oldHandler); }
