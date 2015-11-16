#ifndef __SYS_SOUND__
#define __SYS_SOUND__

#include "System.h"
#include "SFML\Audio.hpp"

class SoundSystem : public ISystem
{
public:
	SoundSystem();
	void update() override{}
	void receiveBroadcast(GameObject* sender, const Message<int>& message);
	void receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message);
private:
	void playSound(sf::Sound& ch, sf::SoundBuffer& buf, float vol = 60);
	sf::Sound m_sndChannel1;
	sf::SoundBuffer m_sndBing;
	sf::SoundBuffer m_sndStep;
};

#endif