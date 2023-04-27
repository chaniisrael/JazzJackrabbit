#pragma once
#include "Button.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ExitGame.h"
#include "NewGame.h"
#include "ExplanationGame.h"
using std::vector;
using std::ifstream;
using std::string;
class Menu
{
public:
	Menu(sf::RenderWindow& window, bool& start);
    Menu() = default;
	~Menu();
	void open();

private:
	void draw();
	vector<std::unique_ptr<Button>>m_button;
	sf::RenderWindow& m_window;
	sf::Sprite m_bgmenu;
};



