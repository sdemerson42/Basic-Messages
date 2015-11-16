#include "Comp_Animator.h"
#include "GameObject.h"
#include "Message.h"

AnimatorComponent::AnimatorComponent()
{
	m_animationIndex = 0;
	m_frameCounter = 0;
	m_lapseCounter = 0;
	m_isTransitioning = false;
}

void AnimatorComponent::update(GameObject* owner)
{
	if (m_animation.size() == 0) return;
	++m_lapseCounter;
	if (m_lapseCounter == m_animation[m_animationIndex].lapse)
	{
		m_lapseCounter = 0;
		++m_frameCounter;
		if (m_frameCounter == m_animation[m_animationIndex].frame.size())
			m_frameCounter = 0;
		owner->sendMessage(*this, Message<int>(Message<int>::MType::animFrameChange, m_animation[m_animationIndex].frame[m_frameCounter]));
	}
	if (m_isTransitioning)
	{
		owner->sendMessage(*this, Message<int>(Message<int>::MType::animFrameChange, m_animation[m_animationIndex].frame[m_frameCounter]));
		m_isTransitioning = false;
	}
}

void AnimatorComponent::addAnimation(const std::string& name, const std::vector<int>& frame, int lapse, bool doesLoop)
{
	m_animation.push_back(Animation(name, frame, lapse, doesLoop));
}

void AnimatorComponent::playAnimation(const std::string& name)
{
	int index = 0;
	for (auto& a : m_animation)
	{
		if (a.name == name && index != m_animationIndex)
		{
			m_animationIndex = index;
			m_frameCounter = 0;
			m_lapseCounter = 0;
			m_isTransitioning = true;
			break;
		}
		++index;
	}
}