#include "System_Sound.h"
#include "Message.h"

SoundSystem::SoundSystem()
{
	m_sndBing.loadFromFile("Sfx/Bing.wav");
	m_sndStep.loadFromFile("Sfx/Step.wav");
};

void SoundSystem::receiveBroadcast(GameObject* sender, const Message<int>& message)
{
	if (message.m_type == Message<int>::MType::pcStep)
		playSound(m_sndChannel1, m_sndStep);
}

void SoundSystem::receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message)
{
	if (message.m_type == Message<sf::Vector2f>::MType::spawnDiamond)
		playSound(m_sndChannel1, m_sndBing);
}

void SoundSystem::playSound(sf::Sound& ch, sf::SoundBuffer& buf, float vol)
{
	ch.setBuffer(buf);
	ch.setVolume(vol);
	m_sndChannel1.play();
}