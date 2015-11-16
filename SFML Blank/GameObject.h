#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <vector>
#include "SFML\Graphics.hpp"

class Renderer;
class IComponent;
template<typename DType>
class Message;
class Broadcaster;

class GameObject
{
public:
	void update(GameObject* owner);
	void addComponent(IComponent* c);
	void connectRenderer(Renderer* r);
	void broadcast(const Message<sf::Vector2f>& message);
	void broadcast(const Message<int>& message);
	void receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message);
	void receiveBroadcast(GameObject* sender, const Message<int>& message);
	void sendMessage(const IComponent& sender, const Message<sf::Vector2f>& message);
	void sendMessage(const IComponent& sender, const Message<int>& message);
	virtual ~GameObject();
protected:
	GameObject(Broadcaster* bc);
	virtual void alertOwner(GameObject* sender, const Message<sf::Vector2f>& message) {}
	virtual void alertOwner(GameObject* sender, const Message<int>& message) {}
	std::vector<IComponent*> m_component;
	Renderer* m_renderer;
	Broadcaster* m_broadcaster;
	sf::Vector2f m_position;
	sf::Vector2f m_texturePosition;
	sf::Vector2f m_textureHome;
	sf::Vector2i m_size;
};

#endif