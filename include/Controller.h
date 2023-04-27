#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "const.h"
#include "GameManager.h"
#include "Menu.h"
#include <iostream>
#include <chrono>
#include <thread>
class Controller
{
public:
	Controller();
	~Controller() = default;
	void run(); //פונקציה שמנהלת את המשחק
protected:
	void gameResult(bool& isSucsses); //פונקציה שבהתאם לתוצאת המשחק(ניצחון או הפסד) מציגה את התמונה והסאונד המתאימים
	sf::RenderWindow m_window; //חלון המשחק
	bool m_start;
	Menu m_menu;//תפריט

};




