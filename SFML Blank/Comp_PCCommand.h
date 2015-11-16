#ifndef __COMP_PC_COMMAND__
#define __COMP_PC_COMMAND__

#include "Component.h"

class PCCommand: public IComponent
{
	virtual void update(GameObject* owner);
};

#endif