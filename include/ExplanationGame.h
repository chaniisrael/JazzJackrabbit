#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <chrono>
#include <thread>
class ExplanationGame : public Button
{
public:
	ExplanationGame(sf::RenderWindow& window) ;
	ExplanationGame() = default;
	~ExplanationGame() = default;
	virtual void execute()override;

protected:
	//bool& m_start;
};

