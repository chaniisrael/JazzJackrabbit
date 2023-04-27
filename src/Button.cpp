#include "Button.h"

Button::Button(sf::RenderWindow& window, std::string str, const sf::Vector2f position) : m_window(window)
{
//	auto it = Resources::getInstance().getImg.find(str);
	/*if (it ==*/m_sprite =sf::Sprite(Resources::getInstance().getImg(str));
	//	exit(1);
	//auto& vec = it->second;
	//m_sprite = sf::Sprite(vec);
	m_sprite.setPosition(position);
}
