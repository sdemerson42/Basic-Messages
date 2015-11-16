#ifndef __RENDERER__
#define __RENDERER__

#include <vector>
#include "SFML\Graphics.hpp"

class Renderer: public sf::Drawable, public sf::Transformable
{
public:
	Renderer(const std::string& texFName);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void reset(int size);
	void addToVa(const sf::Vector2f& position, const sf::Vector2f& texPosition, const sf::Vector2i& size);
private:
	sf::Texture m_texture;
	sf::VertexArray m_va;
	int m_vaIndex;
};

#endif