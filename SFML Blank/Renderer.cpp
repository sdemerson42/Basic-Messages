#include "Renderer.h"

Renderer::Renderer(const std::string& texFName)
{
	m_texture.loadFromFile(texFName);
	m_va.setPrimitiveType(sf::Quads);
	m_va.resize(0);
	m_vaIndex = 0;
}

void Renderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = &m_texture;
	target.draw(m_va, states);
}

void Renderer::reset(int size)
{
	m_va.resize(size);
	m_vaIndex = 0;
}

void Renderer::addToVa(const sf::Vector2f& position, const sf::Vector2f& texPosition, const sf::Vector2i& size)
{
	m_va[m_vaIndex].position = position;
	m_va[m_vaIndex].texCoords = texPosition;
	++m_vaIndex;
	m_va[m_vaIndex].position = m_va[m_vaIndex - 1].position;
	m_va[m_vaIndex].position.x += size.x;
	m_va[m_vaIndex].texCoords = m_va[m_vaIndex - 1].texCoords;
	m_va[m_vaIndex].texCoords.x += size.x;
	++m_vaIndex;
	m_va[m_vaIndex].position = m_va[m_vaIndex - 1].position;
	m_va[m_vaIndex].position.y += size.y;
	m_va[m_vaIndex].texCoords = m_va[m_vaIndex - 1].texCoords;
	m_va[m_vaIndex].texCoords.y += size.y;
	++m_vaIndex;
	m_va[m_vaIndex].position = m_va[m_vaIndex - 1].position;
	m_va[m_vaIndex].position.x -= size.x;
	m_va[m_vaIndex].texCoords = m_va[m_vaIndex - 1].texCoords;
	m_va[m_vaIndex].texCoords.x -= size.x;
	++m_vaIndex;
}