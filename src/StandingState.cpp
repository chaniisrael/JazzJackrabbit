#include <iostream>
#include "StandingState.h"
#include "StateLeaft.h"
#include"StateRight.h"
#include "JumpingState.h"
#include "DownState.h"
#include"Player.h"

unique_ptr<State> StandingState::handleInput(Input input)
{
	if (input == PRESS_RIGHT)
		return make_unique<StateRight>();
	if (input == PRESS_LEAFT)
		return make_unique<StateLeaft>();
	if (input == PRESS_UP)
		return make_unique<JumpingState>();
	if (input == PRESS_DOWN)
		return make_unique<DownState>();

	// Stay in this state.
	return NULL;
}



void StandingState::enter(Player& play)
{

	play.setDirection({ 0,0 });
    // play.setGraphics(IMAGE_STAND);
}
