#pragma once
#include<iostream>
#include"State.h"
#include"Player.h"
//class AttackingState;
class StateRight;
class StateLeaft;
class JumpingState : public State {
public:
	JumpingState();
	~JumpingState() { /* ... */ }

	virtual unique_ptr<State> handleInput(Input input)  override;
	virtual void enter(Player& Player);
protected:
	sf::Clock m_jumpClock;
	bool m_jump;
};