#ifndef __COMP_PC_ANIMATOR__
#define __COMP_PC_ANIMATOR__

#include "Comp_Animator.h"

class PCAnimator : public AnimatorComponent
{
public:
	PCAnimator();
	void receiveMessage(GameObject* sender, const Message<int>& message);
};

#endif