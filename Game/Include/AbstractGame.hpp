#pragma once

#include <ShutdownState.hpp>

class AbstractGame
{
	virtual void SetShutdownState(ShutdownState newState) = 0;
	virtual void Shutdown() = 0;
};