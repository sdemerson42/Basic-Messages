#include "Broadcaster.h"
#include "GameObject.h"
#include "System.h"
#include "Message.h"

void Broadcaster::registerGameObject(GameObject* go)
{
	m_gameObject.push_back(go);
}

void Broadcaster::unregisterGameObject(GameObject* go)
{
	int i = 0;
	for (auto p : m_gameObject)
	{
		if (p == go)
		{
			m_gameObject.erase(m_gameObject.begin() + i);
			break;
		}
		++i;
	}
}

void Broadcaster::registerSystem(ISystem* s)
{
	m_system.push_back(s);
}

void Broadcaster::broadcast(GameObject* sender, const Message<sf::Vector2f>& message)
{
	for (auto p : m_gameObject)
	{
		if (p != sender)
			p->receiveBroadcast(sender, message);
	}
	for (auto p : m_system) p->receiveBroadcast(sender, message);
}

void Broadcaster::broadcast(GameObject* sender, const Message<int>& message)
{
	for (auto p : m_gameObject)
		if (p != sender)
			p->receiveBroadcast(sender, message);
	for (auto p : m_system) p->receiveBroadcast(sender, message);
}