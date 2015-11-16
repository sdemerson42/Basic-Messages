#ifndef __SYS_SPAWNER__
#define __SYS_SPAWNER__

#include "System.h"
#include <vector>

class World;
class Renderer;
class Broadcaster;
class GameObject;

class SpawnerSystem: public ISystem
{
public:
	SpawnerSystem(World* w, Renderer* r, Broadcaster* b);
	void update() override;
	void receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message) override;
private:
	World* m_worldRef;
	Renderer* m_rendererRef;
	Broadcaster* m_broadcasterRef;
	std::vector<Message<sf::Vector2f>> m_spawnQueue;
	std::vector<GameObject*> m_despawnQueue;
};

#endif