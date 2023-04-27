#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "RegularMonster.h"
#include "SpecielMonster.h"
#include "RegularShoot.h"
#include "SpecielShoot.h"
#include "Wall.h"
#include "soil.h" 
#include "Coins.h"
#include "Disqualifications.h"  
//#include "Key.h"
#include "Door.h"
#include "Banana.h"
#include "Pineapple.h"
#include "Keyy.h"
#include "Dokar.h"
#include "MyException.h"
#include "GiftCoins.h"
#include "GiftDisqualifications.h"
#include "GiftTime.h"
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



namespace // anonymous namespace — the standard way to make function "static"
{

	// primary collision-processing functions
	//היתנגשות של שחקן עם מפלצת רגילה
	void playerRegularMonster(GameObject& player,
		GameObject& regularMonster)
	{

		Player& playerr = static_cast<Player&>(player);
		RegularMonster& Monster = static_cast<RegularMonster&>(regularMonster);
		if(Monster.canCollide())
			playerr.setDisqualifications(-2);
	}
	//היתנגשות של שחקן עם מפלצת חכמה
	void playerSpecielMonster(GameObject& player,
		GameObject& specielMonster)
	{
		Player& playerr = static_cast<Player&>(player);
		SpecielMonster& Monster = static_cast<SpecielMonster&>(specielMonster);
		if (Monster.canCollide())
		playerr.setDisqualifications(-4);
	}
	//תנגשות של יריה רגילה בשחקן
	void regularShootPlayer(GameObject& regularShoot,
		GameObject& player)
	{
		RegularShoot& shoot = static_cast<RegularShoot&>(regularShoot);
		Player& playerr = static_cast<Player&>(player);
		playerr.setDisqualifications(-1);
	}
	// התנגשות של יריה חכמה בשחקן
	void specielShootPlayer(GameObject& specielShoot,
		GameObject& player)
	{

		SpecielShoot& shoot = static_cast<SpecielShoot&>(specielShoot);
		Player& playerr = static_cast<Player&>(player);
		playerr.setLife(-1);
	}
	////התנגשןת של יריה רגילה במפלצת רגילה
	//regularShootRegularMonster regularShootSpecielMonster
	void regularShootRegularMonster(GameObject& regularShoot,
		GameObject& regularMonster)
	{
		RegularShoot& shoot = static_cast<RegularShoot&>(regularShoot);
		RegularMonster& regularMonsterr = static_cast<RegularMonster&>(regularMonster);
		regularMonsterr.setLifeS(-5);

	}
	//// התנגשות של יריה רגילה במפלצת משוכללת 
	void regularShootSpecielMonster(GameObject& regularShoot,
		GameObject& specielMonster)
	{
		RegularShoot& shoot = static_cast<RegularShoot&>(regularShoot);
		SpecielMonster& specielMonsterr = static_cast<SpecielMonster&>(specielMonster);
		specielMonsterr.setLifeS(-3);
	}

	////התנגשות של יריה משוכללת במפלצת רגילה
	void specielShootRegularMonster(GameObject& specielShoot,
		GameObject& regularMonster)
	{

		SpecielShoot& shoot = static_cast<SpecielShoot&>(specielShoot);
		RegularMonster& regularMonsterr = static_cast<RegularMonster&>(regularMonster);
		regularMonsterr.setLifeS(-5);
	}
	
	//התנגשות של יריה משוכללת במפלצת משוכללת
	void specielShootSpecielMonster(GameObject& specielShoot,
		GameObject& specielMonster)
	{

		SpecielShoot& shoot = static_cast<SpecielShoot&>(specielShoot);
		SpecielMonster& specielMonsterr = static_cast<SpecielMonster&>(specielMonster);
		specielMonsterr.setLifeS(-10);
	}

	//התנגשות של שחקן בקיר
	void playerWall(GameObject& player,
		GameObject& wall)
	{

		Player& playerr = static_cast<Player&>(player);
		Wall& walll = static_cast<Wall&>(wall);
		playerr.setLocation();
	}
	// התנשגות של שחקן בפסילות
	void playerDisqualifications(GameObject& player,
		GameObject& disqualifications)
	{
		Player& playerr = static_cast<Player&>(player);
		Disqualifications& disqualificationss = static_cast<Disqualifications&>(disqualifications);
		playerr.setDisqualifications(1);
	}
	//התנגשות של שחקן במטבעות
	void playerCoins(GameObject& player,
		GameObject& coins)
	{
		Player& playerr = static_cast<Player&>(player);
		Coins& coinss = static_cast<Coins&>(coins);
		Resources::getInstance().setAndPlaySound("coin", 100);
		playerr.setCoins(10);
	}
	//התנגשות של שחקן באדמה
	void playerSoil(GameObject& player,
		GameObject& Soil)
	{
		Player& playerr = static_cast<Player&>(player);
		soil& soilL = static_cast<soil&>(Soil);
		playerr.setLocation();
	}
	//התנגשות של שחקן במפתח
	void playerKey(GameObject& player,
		GameObject& key)
	{
		Player& playerr = static_cast<Player&>(player);
		Keyy keyyy = static_cast<Keyy&>(key);
		playerr.setKey();
	}
	//התנגשות של שחקן בדלת
	void playerDoor(GameObject& player,
		GameObject& door)
	{
		Player& playerr = static_cast<Player&>(player);
		Door& doorr = static_cast<Door&>(door);
		if (playerr.getKey() == 0)
			throw MyException("h",true); 
	}
	//התנגשות של שחקן בתפוח
	void playerBanana(GameObject& player,
		GameObject& banana)
	{
		Player& playerr = static_cast<Player&>(player);
		Banana& bananaa = static_cast<Banana&>(banana);
		playerr.setFruit(2);
	}
	//התנגשות של שחקן באננס
	void playerPineapple(GameObject& player,
		GameObject& pineapple)
	{
		Player& playerr = static_cast<Player&>(player);
		Pineapple& pineapplee = static_cast<Pineapple&>(pineapple);
		playerr.setFruit(5);
	}
	//התנגשות של שחקן בדוקרנים
	void playerDokar(GameObject& player,
		GameObject& dokar)
	{
		Player& playerr = static_cast<Player&>(player);
		Dokar& dokarr = static_cast<Dokar&>(dokar);
		playerr.setLocation();
		playerr.setPosition({ playerr.getPosition().x - 20,playerr.getPosition().y });
		playerr.setDisqualifications(-1);
	}
	//התנדשות של שחקן במתנת ניקוד
		void playerGiftCoins(GameObject& player,
			GameObject& giftCoins)
	{
		Player& playerr = static_cast<Player&>(player);
		GiftCoins& GiftCoinss = static_cast<GiftCoins&>(giftCoins);
		Resources::getInstance().setAndPlaySound("Gift", 100);
		playerr.setCoins(30);
	}
		//התנדשות של שחקן במתנת פסילות
		void playerGiftDisqualifications(GameObject& player,
			GameObject& disqualifications)
		{
			Player& playerr = static_cast<Player&>(player);
			GiftDisqualifications& Disqualifications = static_cast<GiftDisqualifications&>(disqualifications);
			Resources::getInstance().setAndPlaySound("Gift", 100);
			playerr.setDisqualifications(3);
		}
	  //התנדשות של שחקן במתנת זמן
	  void playerGiftTime(GameObject& player,
		  GameObject& giftTime)
	  {
		  Player& playerr = static_cast<Player&>(player);
		  GiftTime& giftTimee = static_cast<GiftTime&>(giftTime);
		  Resources::getInstance().setAndPlaySound("Gift", 100);
		  playerr.setTime(30);
	  }

	  //התנגשות של מפלצת רגילה  בקיר
	void regularMonsterWall(GameObject& regularMonster,
		GameObject& wall)
	{
		RegularMonster& regularMonsterr = static_cast<RegularMonster&>(regularMonster);
		Wall& Walll = static_cast<Wall&>(wall);
		regularMonsterr.setLocation();
	}
	//התנגשות של מפלצת רגילה באבן
	void regularMonstersoil(GameObject& regularMonster,
		GameObject& Soil)
	{
		RegularMonster& regularMonsterr = static_cast<RegularMonster&>(regularMonster);
		soil& soill = static_cast<soil&>(Soil);
		regularMonsterr.setLocation();
	}
	//התנגשות של מפלצת חכמה בקיר
	void specielMonsterWall(GameObject& specielMonster,
		GameObject& wall)
	{
		SpecielMonster& specielMonsterr = static_cast<SpecielMonster&>(specielMonster);
		Wall& Walll = static_cast<Wall&>(wall);
		specielMonsterr.setLocation();
	}
	//התנגשות של מפלצת רגילה באבן
	void specielMonstersoil(GameObject& specielMonster,
		GameObject& Soil)
	{
		SpecielMonster& specielMonsterr = static_cast<SpecielMonster&>(specielMonster);
		soil& soill = static_cast<soil&>(Soil);
		specielMonsterr.setLocation();
	}
	// secondary collision-processing functions that just
	// implement symmetry: swap the parameters and call a
	// primary function
	void regularMonsterPlayer(GameObject& regularMonster,
		GameObject& player)
	{
	   playerRegularMonster(player, regularMonster);
	}
	
	void specielMonsterPlayer(GameObject& specielMonster,
		GameObject& player)
	{
		playerSpecielMonster(player, specielMonster);
	}
	
	

using HitFunctionPtr = void (*)(GameObject&, GameObject&);
// typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;
//יצירת מפה של כל פונקציות ההתנגשות
HitMap initializeCollisionMap()
{
	HitMap phm;
	phm[Key(typeid(Player), typeid(RegularMonster))] = &playerRegularMonster;
	phm[Key(typeid(Player), typeid(SpecielMonster))] = &playerSpecielMonster;
	phm[Key(typeid(RegularMonster), typeid(Player))] = &regularMonsterPlayer;
	phm[Key(typeid(SpecielMonster), typeid(Player))] = &specielMonsterPlayer;
	phm[Key(typeid(RegularShoot), typeid(Player))] = &regularShootPlayer;
	phm[Key(typeid(SpecielShoot), typeid(Player))] = &specielShootPlayer;

	phm[Key(typeid(RegularShoot), typeid(RegularMonster))] = &regularShootRegularMonster;
	phm[Key(typeid(SpecielShoot), typeid(RegularMonster))] = &specielShootRegularMonster;

	phm[Key(typeid(RegularShoot), typeid(SpecielMonster))] = &regularShootSpecielMonster;
	phm[Key(typeid(SpecielShoot), typeid(SpecielMonster))] = &specielShootSpecielMonster;

	phm[Key(typeid(Player), typeid(Wall))] = &playerWall;
	phm[Key(typeid(Player), typeid(Disqualifications))] = &playerDisqualifications;
	phm[Key(typeid(Player), typeid(Coins))] = &playerCoins;
	phm[Key(typeid(Player), typeid(soil))] = &playerSoil;
	phm[Key(typeid(Player), typeid(Keyy))] = &playerKey;
	phm[Key(typeid(Player), typeid(Door))] = &playerDoor;
	phm[Key(typeid(Player), typeid(Banana))] = &playerBanana;
	phm[Key(typeid(Player), typeid(Pineapple))] = &playerPineapple; 
	phm[Key(typeid(Player), typeid(Dokar))] = &playerDokar;
	phm[Key(typeid(Player), typeid(GiftCoins))] = &playerGiftCoins;
	phm[Key(typeid(Player), typeid(GiftDisqualifications))] = &playerGiftDisqualifications;
	phm[Key(typeid(Player), typeid(GiftTime))] = &playerGiftTime;
	
	phm[Key(typeid(RegularMonster), typeid(Wall))] = &regularMonsterWall;
	phm[Key(typeid(RegularMonster), typeid(soil))] = &regularMonstersoil;

	phm[Key(typeid(SpecielMonster), typeid(Wall))] = &specielMonsterWall;
	phm[Key(typeid(SpecielMonster), typeid(soil))] = &specielMonstersoil;
	
	return phm;
}

HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
	static HitMap collisionMap = initializeCollisionMap();
	auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
	if (mapEntry == collisionMap.end())
	{
		return nullptr;
	}
	return mapEntry->second;
}

} // end namespace
//בודק אם 'קיים פונקציה של התנגשות
void processCollision(GameObject& object1, GameObject& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision(object1, object2);
	}
	phf(object1, object2);
}
