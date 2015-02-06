#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <cstdint>
#include "EventHandler.hpp"
#include "ResourceManager.hpp"
#include "Game.hpp"

//Instantiate and bind classes, set up main window.
class App {
public:
	App(sf::VideoMode mode, std::string title, uint32_t style)
		: 
		MainWindow(mode, title, style), 
		World(MainWindow, WorldEventHandler, WorldResManager), 
		WorldEventHandler(MainWindow, World)
	{}
	~App()
	{}

	bool run();

protected:
	sf::RenderWindow MainWindow;
	sf::Vector2u window_size;

private:
    ResourceManager WorldResManager;
	EventHandler WorldEventHandler;
	Game World;

};

#endif
