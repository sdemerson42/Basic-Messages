#ifndef __WORLD__
#define __WORLD__

#include "SFML\Graphics.hpp"
#include <vector>

class Renderer;
class GameObject;
class Broadcaster;
class ISystem;

class World: public sf::Drawable, public sf::Transformable
{
public:
	World();
	~World();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void addGameObject(GameObject* newObj);
	void removeGameObject(GameObject* obj);
	void update();
private:
	Renderer* m_renderer;
	Broadcaster* m_broadcaster;
	std::vector<ISystem*> m_system;
	std::vector<GameObject*> m_gameObject;
};

#endif