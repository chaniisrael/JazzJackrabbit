#pragma once
#include<iostream>
#include"State.h"
class player;
//class DuckingState;
class JumpingState;

class StandingState : public State {
public:
	~StandingState() { }

	unique_ptr<State> handleInput(Input input);

	virtual void enter(Player& play);

};