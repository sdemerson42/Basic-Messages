#ifndef __I_COMPONENT__
#define __I_COMPONENT__

#include "SFML\Graphics.hpp"

class GameObject;
template<typename DType>
class Message;

class IComponent
{
public:
	virtual void update(GameObject* owner) = 0;
	virtual void receiveMessage(GameObject* sender, const Message<sf::Vector2f>& message) {}
	virtual void receiveMessage(GameObject* sender, const Message<int>& message) {}
	virtual ~IComponent(){}
};

#endif