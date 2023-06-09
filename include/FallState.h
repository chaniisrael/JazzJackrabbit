#pragma once
#include "State.h"
#include<memory>

class FallState :public State
{
public:
	~FallState() = default;
	virtual std::unique_ptr<State> handleInput(Input input)override;
	virtual void enter(Player& play)override;


protected:

};