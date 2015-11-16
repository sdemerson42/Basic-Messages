#include "World.h"
#include "System_Spawner.h"
#include "System_Sound.h"
#include "Renderer.h"
#include "Broadcaster.h"
#include "PC.h"
#include "Diamond.h"

World::World()
{
	m_renderer = new Renderer("Gfx/Texture1.png");
	m_broadcaster = new Broadcaster();
	m_system.push_back(new SpawnerSystem(this, m_renderer, m_broadcaster));
	m_system.push_back(new SoundSystem);
	m_broadcaster->registerSystem(m_system[0]);
	m_broadcaster->registerSystem(m_system[1]);
	addGameObject(new Diamond(m_renderer, m_broadcaster));
	addGameObject(new PC(m_renderer, m_broadcaster));
}

World::~World()
{
	delete m_renderer;
	delete m_broadcaster;
	for (auto p : m_system) delete p;
	for (auto p : m_gameObject) delete p;
}

void World::addGameObject(GameObject* newObj)
{
	m_gameObject.push_back(newObj);
	m_broadcaster->registerGameObject(newObj);
}

void World::removeGameObject(GameObject* obj)
{
	int i = 0;
	for (auto p : m_gameObject)
	{
		if (p == obj)
		{
			m_broadcaster->unregisterGameObject(obj);
			m_gameObject.erase(m_gameObject.begin() + i);
			break;
		}
		++i;
	}
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*m_renderer);
}

void World::update()
{
	m_renderer->reset(m_gameObject.size() * 4);
	for (auto p : m_gameObject) p->update(p);
	for (auto p : m_system) p->update();
}