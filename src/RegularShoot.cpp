#include "RegularShoot.h"

RegularShoot::RegularShoot( const sf::Vector2f& location, float height, float width) : ShootType ("shootR",location, height,  width)
{

}
void RegularShoot::move(sf::Time deltaTime)
{
	calculateSpeed(m_direction, SPEEDSHOOT);
	m_sprite.setPosition({ 0,100 });
		m_sprite.move(m_direction * deltaTime.asSeconds());
	
}
