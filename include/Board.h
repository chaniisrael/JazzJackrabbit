#pragma once
#include <string>
#include <fstream>
#include "StaticObject.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Resources.h"
#include "Factory.h"
#include "MyException.h"
#include "const.h"
#include <memory>
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Player.h"
#include "MonsterType.h"
#include "soil.h"
#include "Dokar.h"
#include "State.h"
#include "DownState.h"
#include "const.h"
#include "Door.h"
#include "MyException.h"
using std::vector;
using std::ifstream;
using std::string;
using std::getline;
using std::nothrow;
struct Win{};
class Level;
class Board
{
public:
	Board(const std::string fileName, vector<std::unique_ptr<MonsterType>>& monster, Player& player);
	Board() = default;
	~Board() = default;
	void draw(sf::RenderWindow& window,int numOfLevel); //פונקציה שמציגה את הלוח על המסך
	void run(Player& player, vector<std::unique_ptr<MonsterType>>& monster);
	void openBoardFile();
	void setObject(Player& player,char character, sf::Vector2f location, vector<std::unique_ptr<MonsterType>>& monster,int seconds, int key);
	//bool checkIfEmpty(sf::Vector2f cell);
	//void openBoardFile();
	//void readFile();
	//void run();
	void playerCollideWithStaticObjectt(Player& player);
	void monsterCollideWithStaticObjectt(vector<std::unique_ptr<MonsterType>>&monster);
	void updatBackgroundPosition();

	

protected:
	ifstream m_file;
	vector<std::unique_ptr<StaticObjet>>m_gameBoard;
	//std::unique_ptr<State> m_state;
};

