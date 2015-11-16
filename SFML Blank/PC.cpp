#include "PC.h"
#include "Renderer.h"
#include "Component.h"
#include "Comp_PCAnimator.h"
#include "Comp_PCCommand.h"
#include "Message.h"
#include "Broadcaster.h"

PC::PC(Renderer* r, Broadcaster* br): GameObject(br)
{
	connectRenderer(r);
	m_position = sf::Vector2f(0, 0);
	m_texturePosition = sf::Vector2f(0, 0);
	m_textureHome = sf::Vector2f(0, 0);
	m_size = sf::Vector2i(32, 32);

	m_component.push_back(new PCCommand);
	m_component.push_back(new PCAnimator);
}

void PC::alertOwner(GameObject* sender, const Message<int>& message)
{
	if (message.m_type == Message<int>::MType::pcUp)
	{
		m_position.y -= 3;
		broadcast(Message<sf::Vector2f>(Message<sf::Vector2f>::MType::pcLocation, m_position));
	}
	if (message.m_type == Message<int>::MType::pcDown)
	{
		m_position.y += 3;
		broadcast(Message<sf::Vector2f>(Message<sf::Vector2f>::MType::pcLocation, m_position));
	}
	if (message.m_type == Message<int>::MType::pcLeft)
	{
		m_position.x -= 3;
		broadcast(Message<sf::Vector2f>(Message<sf::Vector2f>::MType::pcLocation, m_position));
	}
	if (message.m_type == Message<int>::MType::pcRight)
	{
		m_position.x += 3;
		broadcast(Message<sf::Vector2f>(Message<sf::Vector2f>::MType::pcLocation, m_position));
	}

	if (message.m_type == Message<int>::MType::animFrameChange)
	{
		m_texturePosition.x = m_textureHome.x + (m_size.x * message.m_data);
	}
}

