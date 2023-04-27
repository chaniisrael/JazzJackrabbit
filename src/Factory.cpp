#include "Factory.h"
//#include "StaticObject.h"
//#include "MonsterType.h"
//בודקת אם האוביקטקיים על המפה
std::unique_ptr<StaticObjet> Factory::create(const std::string& name, const sf::Vector2f& location, float height, const float width) {
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(location,height, width);
}
//הפונקציה יוצרת את האוביקט הסטטי
bool Factory::registerit(const std::string& name, std::unique_ptr<StaticObjet>(*f)(const sf::Vector2f& location, float height, const float width))
{
	getMap().emplace(name,f);
	return true;
}
//מפלצות
std::unique_ptr<MonsterType> Factory::createMonster(const std::string& name, const sf::Vector2f& location, float height, float width, Player& player)
{
	std::cout << "open1";
	auto it = getMapMonster().find(name);
	if (it == getMapMonster().end())
		return nullptr;
	return it->second(location, height, width,player);
}
//מפלצות
bool Factory::registeritMonster(const std::string& name,std::unique_ptr<MonsterType>(*f)(const sf::Vector2f& location, float height, float width, Player& player))
{
	std::cout << "open2";
	getMapMonster().emplace(name,f);
	return true;

}
//מתנות
std::unique_ptr<GiftType> Factory::createGift(const sf::Vector2f& location, float height, float width)
{
	int typeOfVecc = rand() % getVecGift().size();
	return getVecGift()[typeOfVecc](location, height, width);

}
//מתנות
bool Factory::registeritGift(std::unique_ptr<GiftType>(*f)(const sf::Vector2f& location, float height, float width))
{
	getVecGift().emplace_back(f);
	return true;

}
std::unique_ptr<ShootType> Factory::createShoot(const std::string& name, const sf::Vector2f& location, float height, const float width)
{
	auto it = getMapcShoot().find(name);
	if (it == getMapcShoot().end())
		return nullptr;

	return it->second(location, height, width);
}

bool Factory::registeritShoot(const std::string& name, std::unique_ptr<ShootType>(*f)(const sf::Vector2f& location, float height, const float width))
{
	getMapcShoot().emplace(name, f);
	return true;
}

//בודק עם הסוג יריה נמצא במפה
//std::unique_ptr<ShootType> Factory::createShoot(const std::string& name, sf::Vector2f location, float height, float width)
//{
//	auto it = getMepShoot().find(name);
//	if (it == getMepShoot().end())
//		return nullptr;
//	return it->second(location, height, width);
//}
////יוצרת את סוג היריה
//bool Factory::registeritShoot(const std::string& name, std::unique_ptr<ShootType>(*f)(sf::Vector2f location, float height, float width))
//{
//	getMepShoot().emplace(name, f);
//	return true;
//}

mymap& Factory::getMap()
{
	static mymap m_map;
	return m_map;	
}

monstr& Factory::getMapMonster()
{
	static monstr m_mapMonster;
	return m_mapMonster;
}
gift& Factory::getVecGift()
{
	static gift m_vecGift;
	return m_vecGift;
}
mapshoot& Factory::getMapcShoot()
{
	static mapshoot m_mapShoot;
	return m_mapShoot;
}

//shoot& Factory::getMepShoot()
//{
//	static shoot m_shootMap;
//	return m_shootMap;
//}




