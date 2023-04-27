#pragma once
#include "MonsterType.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "InformationDisplay.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "CollisionHandling.h"
#include "Resources.h"
using std::vector;
using std::ifstream;
using std::string;
class  Level
{
public:
	 Level(const std::string fileName,Player& player);
	~ Level();
	bool run(sf::RenderWindow& window, const int& numOfLevel,Player& player);
	void draw(sf::RenderWindow& window,Player& player);
	void CheckLevelEvents(sf::RenderWindow& window, Player& player);
	void move(Player& m_player);
	sf::Time getDeltaTime();
	void mainCollision(Player& player);
	void playerCollideWithStaticObject(Player& player);
	void playerCollideWithMonster(Player& player);
	void monsterCollideWithStaticObject();
private:
	
	sf::Clock m_clock;
	sf::Clock m_timePassed;
	InformationDisplay m_informationDisplay;
	vector<std::unique_ptr<MonsterType>>m_monster;
	Board m_board;
	sf::Sprite m_background1;
	sf::Sprite m_background2;
};


