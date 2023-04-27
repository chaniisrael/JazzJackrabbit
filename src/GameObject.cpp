#include "GameObject.h"
#include <iostream>


GameObject::GameObject(const std::string& name, const sf::Vector2f& location,  float height, float width)
{
	setObjet(name,location,  height,  width);
}

 void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
 //מסדר את המיקום והגודל של התמונה
void GameObject::setObjet(const std::string& name, const sf::Vector2f& location,  float height,  float width)
{	
		m_sprite.setPosition(location);
		m_sprite.setTexture(Resources::getInstance().getImg(name));
		auto texture = m_sprite.getTexture();
		m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
		auto texSize = texture->getSize();
		std::cout << texSize.x << "  " << texSize.y;
		auto newTexSize = sf::Vector2u(width, height);
		auto scaleX = newTexSize.x * 1.00f / texSize.x;
		auto scaleY = newTexSize.y * 1.00f / texSize.y;
		m_sprite.setScale(scaleX, scaleY); 
}

sf::FloatRect GameObject::getGlobalBoundsOfSprite()
{
	return m_sprite.getGlobalBounds();
}
