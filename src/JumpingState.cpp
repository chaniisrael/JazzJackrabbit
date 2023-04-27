#include "JumpingState.h"
#include"StateLeaft.h"
#include"StateRight.h"
#include "StandingState.h"


JumpingState::JumpingState() :m_jump(true)
{
	m_jumpClock.restart();
}

unique_ptr<State> JumpingState::handleInput(Input input)
{
	

		if (input == PRESS_LEAFT)
			return make_unique<StateLeaft>();
		if (input == PRESS_RIGHT)
			return make_unique<StateRight>();
		if (input == PRESS_STOP)
			return make_unique<StandingState>();

	return NULL;
}

void JumpingState::enter(Player& Player)
{

	

	if (m_jumpClock.getElapsedTime().asSeconds() < 3.0f)
		Player.setDirection({0, -200});
	
	if (m_jumpClock.getElapsedTime().asSeconds() > 1.0f && m_jumpClock.getElapsedTime().asSeconds() < 2.0f)
		Player.setDirection({ 0, 200 });


	if (m_jumpClock.getElapsedTime().asSeconds() > 2.0f)
		Player.handleInput(PRESS_STOP);

}