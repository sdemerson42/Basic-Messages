#include "GameObject.h"
#include "Renderer.h"
#include "Component.h"
#include "Message.h"
#include "Broadcaster.h"

GameObject::GameObject(Broadcaster* bc)
{
	m_renderer = nullptr;
	m_broadcaster = bc;
}

GameObject::~GameObject()
{
	for (auto p : m_component) delete p;
}

void GameObject::update(GameObject* owner)
{
	for (auto p : m_component) p->update(owner);
	if (m_renderer != nullptr)
	{
		m_renderer->addToVa(m_position, m_texturePosition, m_size);
	}
}

void GameObject::broadcast(const Message<sf::Vector2f>& message)
{
	m_broadcaster->broadcast(this, message);
}

void GameObject::broadcast(const Message<int>& message)
{
	m_broadcaster->broadcast(this, message);
}

void GameObject::receiveBroadcast(GameObject* sender, const Message<sf::Vector2f>& message)
{
	alertOwner(sender, message);
	for (auto p : m_component) p->receiveMessage(sender, message);
}

void GameObject::receiveBroadcast(GameObject* sender, const Message<int>& message)
{
	alertOwner(sender, message);
	for (auto p : m_component) p->receiveMessage(sender, message);
}


void GameObject::sendMessage(const IComponent& sender, const Message<sf::Vector2f>& message)
{
	alertOwner(this, message);
	for (auto p : m_component) p->receiveMessage(this, message);
}

void GameObject::sendMessage(const IComponent& sender, const Message<int>& message)
{
	alertOwner(this, message);
	for (auto p : m_component) p->receiveMessage(this, message);
}

void GameObject::addComponent(IComponent* c)
{
	m_component.push_back(c);
}

void GameObject::connectRenderer(Renderer* r)
{
	m_renderer = r;
}
