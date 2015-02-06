#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "EventHandler.hpp"

class EventHandler;
class ResourceManager;

//Rendering and gameloop
class Game
{
public:
	Game(sf::RenderWindow& Draw, EventHandler& EH, ResourceManager& RM) 
		: 
		DrawWindow(Draw), 
		GameEventHandler(EH), 
		GameResourceManager(RM), 
		quit_state(false),
		vsync_state(true)
	{}
	~Game()
	{}

	bool startGameloop();

    void quit(){ quit_state = true; }
    void toggleVsync(){ vsync_state = !vsync_state; DrawWindow.setVerticalSyncEnabled(vsync_state);}

protected:
	bool quit_state, vsync_state;
	sf::Clock frame_clock;
	sf::Time frame_time;

private:
	sf::RenderWindow &DrawWindow;
	EventHandler &GameEventHandler;
	ResourceManager &GameResourceManager;

	bool eventLoop();
	bool renderLoop();
    bool drawResources();
	
};

#endif
