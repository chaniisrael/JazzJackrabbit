#pragma once
#include<iostream>
#include"State.h"
#include"JumpingState.h"
#include "Player.h"
#include "DownState.h"

class StateRight;
class StateLeaft : public State
{
public:
	~StateLeaft() { /* ... */ }

	virtual unique_ptr<State> handleInput(Input input)  override;
	virtual void enter(Player& play);


};