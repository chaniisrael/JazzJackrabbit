#include "DownState.h"
#include"Player.h"
#include"StateLeaft.h"
#include"StateRight.h"
#include"JumpingState.h"
#include"DownState.h"
unique_ptr<State> DownState::handleInput(Input input)
{

	if (input == PRESS_LEAFT)
		return make_unique<StateLeaft>();
	if (input == PRESS_RIGHT)
		return make_unique<StateRight>();
	if (input == PRESS_STOP)
		return make_unique<StandingState>();
	if (input == PRESS_UP)
		return make_unique<JumpingState>();

	return (NULL);
}

void DownState::enter(Player& play)
{
	play.setDirection({0,200});
}
