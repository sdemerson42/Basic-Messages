#ifndef __I_SYSTEM__
#define __I_SYSTEM__

#include "SFML\Graphics.hpp"

class GameObject;
template<typename DType>
class Message;

class ISystem
{
public:
	virtual void update() = 0;
	virtual void receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message) {}
	virtual void receiveBroadcast(GameObject* sender, const Message<int>& message) {}
};

#endif