#ifndef __COMP_ANIMATOR__
#define __COMP_ANIMATOR__

#include "Component.h"
#include <vector>

class AnimatorComponent: public IComponent
{
public:
	void update(GameObject* owner);
	virtual void receiveMessage(GameObject* sender, const Message<int>& message) {}
	virtual ~AnimatorComponent(){}
protected:
	AnimatorComponent();
	void addAnimation(const std::string& name, const std::vector<int>& frame, int lapse, bool doesLoop = true);
	void playAnimation(const std::string& name);
private:
	struct Animation
	{
		Animation(const std::string& _name, const std::vector<int>& _frame, int _lapse, bool _doesLoop = true) :
			name(_name), frame(_frame), lapse(_lapse), doesLoop(_doesLoop) {}
		std::string name;
		std::vector<int> frame;
		int lapse;
		bool doesLoop;
	};
	std::vector<Animation> m_animation;
	int m_animationIndex;
	int m_lapseCounter;
	int m_frameCounter;
	bool m_isTransitioning;
};

#endif