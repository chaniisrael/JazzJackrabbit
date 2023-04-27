#include "Resources.h"

Resources& Resources::getInstance()
{
	static Resources m_instance;
	return m_instance;
}
sf::Texture& Resources::getImg(std::string img)
{
	auto it = m_images.find(img);
	if (it == m_images.end())
		exit(1);
	return m_images.find(img)->second;
}
std::unique_ptr<sf::Music>& Resources::getMusic(std::string music)
{
	return m_music.find(music)->second;
}
sf::SoundBuffer& Resources::getSound(std::string sound)
{
	return m_soundBuffer.find(sound)->second;
}
void Resources::setAndPlaySound(std::string sound, float vol)
{
m_sound.setBuffer(m_soundBuffer[sound]);
m_sound.setVolume(vol);
m_sound.play();
}
void Resources::stopSound(std::string sound)
{

	m_sound.setBuffer(m_soundBuffer[sound]);
	m_sound.stop();
}
Resources::Resources()
{
	insertImageToMap();
	pushMusicToMap();
}
void Resources::insertImageToMap()
{
	auto image = sf::Texture();

	image.loadFromFile("player.png");
	m_images.insert(std::make_pair("player",image)); //הכנסת התמונה לווקטור

	image.loadFromFile("wall3.png");
	m_images.insert(std::make_pair("wall", image)); //הכנסת התמונה לווקטור

	image.loadFromFile("background1.jpg");
	m_images.insert(std::make_pair("background0", image));

	image.loadFromFile("background2.gif");
	m_images.insert(std::make_pair("background1", image));

	image.loadFromFile("background3.jpg");
	m_images.insert(std::make_pair("background2", image));

	image.loadFromFile("chani1.gif");
	m_images.insert(std::make_pair("chani1", image));

	image.loadFromFile("coin2.png");
	m_images.insert(std::make_pair("coin", image));

	image.loadFromFile("RegularMonster.png");
	m_images.insert(std::make_pair("monsterR", image));

	image.loadFromFile("monsterS.gif");
	m_images.insert(std::make_pair("monsterS", image));

	image.loadFromFile("soil.png");
	m_images.insert(std::make_pair("soil", image));

	image.loadFromFile("door4.png");
	m_images.insert(std::make_pair("door", image));

	image.loadFromFile("key3.png");
	m_images.insert(std::make_pair("key", image));

	image.loadFromFile("setting.png");
	m_images.insert(std::make_pair("setting", image));

	image.loadFromFile("exit.PNG");
	m_images.insert(std::make_pair("exit", image));

	image.loadFromFile("play.PNG");
	m_images.insert(std::make_pair("play", image));

	image.loadFromFile("Help.PNG");
	m_images.insert(std::make_pair("Help", image));

	image.loadFromFile("life2.png");
	m_images.insert(std::make_pair("Life", image));

	image.loadFromFile("apple2.png");
	m_images.insert(std::make_pair("banana", image));

	image.loadFromFile("pineapple.png");
	m_images.insert(std::make_pair("pineapple", image));

	image.loadFromFile("BulletGift.png");
	m_images.insert(std::make_pair("Gift", image));

	image.loadFromFile("lifejj.png");
	m_images.insert(std::make_pair("life", image));

	image.loadFromFile("psilot2.jpg");
	m_images.insert(std::make_pair("psilot", image)); 

     image.loadFromFile("playerrr.png");
	m_images.insert(std::make_pair("playerrr", image)); 

	image.loadFromFile("dokar.png");
	m_images.insert(std::make_pair("dokar", image));

	image.loadFromFile("bb.jpg");
	m_images.insert(std::make_pair("bb", image)); 

    image.loadFromFile("gameOver.jpg");
	m_images.insert(std::make_pair("gameOver", image)); 

    image.loadFromFile("shootR.png");
	m_images.insert(std::make_pair("shootR", image)); 

    image.loadFromFile("GameWin.jpg");
	m_images.insert(std::make_pair("GameWin", image));

	image.loadFromFile("help11.png");
	m_images.insert(std::make_pair("help11", image));

	m_font.loadFromFile("c:/Windows/Fonts/Forte.ttf");
}

void Resources::pushMusicToMap()
{
	m_music["BackgroundMusic"] = std::make_unique< sf::Music >();
	m_music["BackgroundMusic"]->openFromFile("BackgroundMusic.wav");
	m_music["BackgroundMusic"]->setVolume(40);

	m_music["GameOverMusic"] = std::make_unique< sf::Music >();
	m_music["GameOverMusic"]->openFromFile("GameOverMusic.wav");
	m_music["GameOverMusic"]->setVolume(40);

	m_music["GameWin"] = std::make_unique< sf::Music >();
	m_music["GameWin"]->openFromFile("GameWin.wav");
	m_music["GameWin"]->setVolume(40);

	m_soundBuffer["Gift"] = sf::SoundBuffer();
	m_soundBuffer["Gift"].loadFromFile("Gift.wav");

	m_soundBuffer["coin"] = sf::SoundBuffer();
	m_soundBuffer["coin"].loadFromFile("coin.wav");


}
