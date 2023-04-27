#pragma once
#include<iostream>
#include"State.h"


class DownState : public State {
public:
	~DownState() { /* ... */ }

	virtual unique_ptr<State> handleInput(Input input)  override;
	virtual void enter(Player& play);


};