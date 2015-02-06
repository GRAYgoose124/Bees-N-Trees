#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

class Game;

//Handle events: user input, screen changes
class EventHandler
{
public:
	EventHandler(sf::RenderWindow& W, Game& G)
		: 
		WorldWindow(W), 
		World(G)
	{}
	~EventHandler()
	{}

	sf::Vector2i mouse_pos;

	bool pollWindowEvents();

protected:
	sf::Event WindowEvent;

private:
	sf::RenderWindow &WorldWindow;
	Game &World;

	bool handleMouse();
	bool handleKeyboard();
};

#endif
