#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Player.h"
#include "Resources.h"
class GameManager
{
public:
	GameManager();
	bool run(sf::RenderWindow& window);
private:
	Player m_player;
};
