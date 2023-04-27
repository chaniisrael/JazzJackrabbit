#include "FallState.h"
#include "JumpingState.h"
#include "StandingState.h"
#include "Player.h"
std::unique_ptr<State> FallState::handleInput(Input input)
{
	if (input == PRESS_UP)
	{
		return std::make_unique<JumpingState>();
	}
	
	if (input == PRESS_STOP)
	{
		return std::make_unique<StandingState>();
	}
	return NULL;
}
void FallState::enter(Player& play)
{
	
	//mario.setDirection(sf::Vector2f(0,1));
	//mario.setGraphics(PlayerGo);
	//dave.setDirection(sf::Vector2f(0, 1));
	play.setDirection({ 0,60});
	//mario.Move( deltaTime);
}