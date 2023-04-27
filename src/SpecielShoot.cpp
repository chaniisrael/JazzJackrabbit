#include "SpecielShoot.h"

SpecielShoot::SpecielShoot( const sf::Vector2f& location, float height, float width) : ShootType("shootR",location, height, width)
{
	//m_sprite.setTexture(Resources::getInstance().m_images["shootR"]);
	/*auto texture = m_sprite.getTexture();
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
	auto texSize = texture->getSize();
	std::cout << texSize.x << "  " << texSize.y;
	auto newTexSize = sf::Vector2u(width, height);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	m_sprite.setScale(scaleX, scaleY);*/
}

void SpecielShoot::move(sf::Time deltaTime)
{
}