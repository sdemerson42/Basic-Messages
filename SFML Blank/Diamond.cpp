#include "Diamond.h"
#include "Message.h"

Diamond::Diamond(Renderer* r, Broadcaster* b): GameObject(b)
{
	m_renderer = r;
	m_position = sf::Vector2f(rand() % 600, rand() % 600);
	m_textureHome = sf::Vector2f(0, 32);
	m_texturePosition = sf::Vector2f(0, 32);
	m_size = sf::Vector2i(32, 32);
}

void Diamond::alertOwner(GameObject* sender, const Message<sf::Vector2f>& message)
{
	if (message.m_type == Message<sf::Vector2f>::MType::pcLocation)
	{
		float x = message.m_data.x - m_position.x;
		float y = message.m_data.y - m_position.y;
		float dist = sqrt(x * x + y * y);
		if (dist < 10)
		{
			broadcast(Message<sf::Vector2f>(Message<sf::Vector2f>::MType::despawn, sf::Vector2f(0, 0)));
			broadcast(Message<sf::Vector2f>(Message<sf::Vector2f>::MType::spawnDiamond, sf::Vector2f(0, 0)));
		}
		else if (10 <= dist && dist < 30) m_texturePosition.x = 128;
		else if (30 <= dist && dist < 60) m_texturePosition.x = 96;
		else if (60 <= dist && dist < 90) m_texturePosition.x = 64;
		else if (90 <= dist && dist < 120) m_texturePosition.x = 32;
		else m_texturePosition.x = 0;
	}
}