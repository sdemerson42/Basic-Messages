#ifndef __DIAMOND__
#define __DIAMOND__

#include "GameObject.h"

class Diamond : public GameObject
{
public:
	Diamond(Renderer* r, Broadcaster* b);
protected:
	void alertOwner(GameObject* sender, const Message<sf::Vector2f>& message);
};

#endif