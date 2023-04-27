 #include "StateLeaft.h"
#include"StateRight.h"


unique_ptr<State> StateLeaft::handleInput(Input input)
{
	if (input == PRESS_RIGHT)
		return make_unique<StateRight>();
	if (input == PRESS_UP)
		return make_unique<JumpingState>();
	if (input == PRESS_DOWN)
		return make_unique<DownState>();
	if (input == PRESS_STOP)
		return make_unique<StandingState>();

	return NULL;
}

void StateLeaft::enter(Player& play)
{
	play.setDirection({ -300,0});


}
