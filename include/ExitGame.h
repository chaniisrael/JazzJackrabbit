#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class ExitGame : public Button
{
public:
	ExitGame(sf::RenderWindow& window);
	ExitGame() = default;
	~ExitGame() = default;
	virtual void execute()override;

protected:

};
