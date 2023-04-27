#pragma once
#include<iostream>
#include"State.h"

#include"JumpingState.h"
#include "Player.h"
#include "const.h"
class StateLeaft;
class StateRight : public State {
public:
	~StateRight() { /* ... */ }

	virtual unique_ptr<State> handleInput(Input input)  override;
	virtual void enter(Player& play);
	

};