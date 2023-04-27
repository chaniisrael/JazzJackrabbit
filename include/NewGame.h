#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Level.h"
class NewGame : public Button
{
public:
	NewGame(sf::RenderWindow& window, bool& start);
	NewGame() = default;
	~NewGame() = default;
	virtual void execute()override;

protected:
	bool& m_start;
	
};