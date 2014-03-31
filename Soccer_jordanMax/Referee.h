#pragma once
#include "2D/Vector2D.h"
#include "PlayerBase.h"
#include "FSM/StateMachine.h"

class PlayerBase;

class Referee : public PlayerBase
{
public:
	Referee();
	~Referee();
};

