#include "System_Spawner.h"

#include "GameObject.h"
#include "Message.h"
#include "World.h"
#include "Renderer.h"
#include "Broadcaster.h"

#include "Diamond.h"

SpawnerSystem::SpawnerSystem(World* w, Renderer* r, Broadcaster* b)
{
	m_worldRef = w;
	m_rendererRef = r;
	m_broadcasterRef = b;
}

void SpawnerSystem::update()
{
	for (auto& p : m_despawnQueue) m_worldRef->removeGameObject(p);

	for (auto& p : m_spawnQueue)
	{
		if (p.m_type == Message<sf::Vector2f>::MType::spawnDiamond)
			m_worldRef->addGameObject(new Diamond(m_rendererRef, m_broadcasterRef));
	}

	if (m_spawnQueue.size() > 0)  m_spawnQueue.clear();
	if (m_despawnQueue.size() > 0) m_despawnQueue.clear();
}

void SpawnerSystem::receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message)
{
	if (message.m_type == Message<sf::Vector2f>::MType::spawnDiamond)
		m_spawnQueue.push_back(message);
	if (message.m_type == Message<sf::Vector2f>::MType::despawn)
		m_despawnQueue.push_back(sender);
}