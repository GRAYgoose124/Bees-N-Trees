#include "App.hpp"

bool App::run()
{
	World.startGameloop();
	MainWindow.close();

	return true;
}