#include "Comp_PCAnimator.h"
#include "Message.h"
#include "GameObject.h"

PCAnimator::PCAnimator()
{
	addAnimation("walk", std::vector < int > {0, 1}, 8);
	addAnimation("idle", std::vector < int > {0}, 8);
	playAnimation("idle");
}

void PCAnimator::receiveMessage(GameObject* sender, const Message<int>& message)
{
	if (message.m_type == Message<int>::MType::pcIdle) playAnimation("idle");
	if (message.m_type == Message<int>::MType::pcMove) playAnimation("walk");
}