#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <vector>
#include "const.h"
class Resources
{
public:

	~Resources() = default;
	static Resources& getInstance();
	sf::Texture& getImg(std::string img);
	std::unique_ptr<sf::Music>& getMusic(std::string music);
	sf::SoundBuffer& getSound(std::string sound);///
	void setAndPlaySound(std::string sound, float vol = 100);
	void stopSound(std::string sound);

	std::vector<sf::Texture>m_background;
	sf::Font m_font;
	sf::Sound m_sound;
protected:
	std::map<std::string, sf::Texture>m_images;
	std::map<std::string, std::unique_ptr<sf::Music>> m_music;
	std::map<std::string, sf::SoundBuffer> m_soundBuffer;

	Resources();
	Resources(const Resources& other) = default;
	//Recources& operator=(const Resources& other) = default;
	void insertImageToMap();
	void pushMusicToMap();
	//sf::Texture m_texture;
};


