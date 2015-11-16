#ifndef __PC__
#define __PC__

#include "GameObject.h"

class Renderer;

class PC : public GameObject
{
public:
	PC(Renderer* r, Broadcaster* br);
protected:
	void alertOwner(GameObject* sender, const Message<int>& message);
};

#endif