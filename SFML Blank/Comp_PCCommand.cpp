#include "Comp_PCCommand.h"
#include "GameObject.h"
#include "SFML\System.hpp"
#include "Message.h"

void PCCommand::update(GameObject* owner)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcUp, 0));
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcMove, 0));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcDown, 0));
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcMove, 0));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcLeft, 0));
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcMove, 0));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcRight, 0));
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcMove, 0));
	}

	else
	{
		owner->sendMessage(*this, Message<int>(Message<int>::MType::pcIdle, 0));
	}
}