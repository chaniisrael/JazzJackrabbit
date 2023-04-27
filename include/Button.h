#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include"Resources.h"
class Button
{
public:
	Button(sf::RenderWindow& window, std::string str, const sf::Vector2f position);
	Button() = default;
	~Button() = default;
	virtual void execute() = 0;
	virtual void draw(sf::RenderWindow& window) { window.draw(m_sprite); };
	bool isInRect(sf::Vector2f possition) { return(m_sprite.getGlobalBounds().contains(possition)); }

protected:
	sf::Sprite m_sprite;
	sf::RenderWindow& m_window;

};

