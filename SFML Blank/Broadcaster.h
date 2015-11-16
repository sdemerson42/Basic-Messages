#ifndef __BROADCASTER__
#define __BROADCASTER__

#include <vector>
#include "SFML\Graphics.hpp"

class GameObject;
class ISystem;
template<typename DType>
class Message;

class Broadcaster
{
public:
	void registerGameObject(GameObject* go);
	void unregisterGameObject(GameObject* go);
	void registerSystem(ISystem* s);
	void broadcast(GameObject* sender, const Message<sf::Vector2f>& message);
	void broadcast(GameObject* sender, const Message<int>& message);
private:
	std::vector<GameObject*> m_gameObject;
	std::vector<ISystem*> m_system;
};

#endif