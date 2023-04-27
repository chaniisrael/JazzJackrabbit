#include "StateRight.h"
#include"StateLeaft.h"
#include "StandingState.h"
unique_ptr<State> StateRight::handleInput(Input input)
{
	if (input == PRESS_LEAFT)
		return make_unique<StateLeaft>();
	if (input == PRESS_UP)
		return make_unique<JumpingState>();
	if (input == PRESS_DOWN)
		return make_unique<DownState>();
	if (input == PRESS_STOP)
		return make_unique<StandingState>();
	return NULL;

}

void StateRight::enter(Player& play)
{
	play.setDirection({ 300,0 });


}
