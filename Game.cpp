#include "Game.hpp"

bool Game::startGameloop()
{
	while (!quit_state)
	{
		frame_clock.restart();

		eventLoop();
		renderLoop();

		frame_time = frame_clock.getElapsedTime();
	}

	return true;
}

bool Game::eventLoop()
{
	GameEventHandler.pollWindowEvents();

	return true;
}

bool Game::renderLoop()
{
	DrawWindow.clear();

    drawResources();

	DrawWindow.display();

	return true;
}

bool Game::drawResources()
{


    return true;
}
