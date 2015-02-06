#include "config.hpp"
#include "App.hpp"

int main(int argc, char *argv[])
{
    App gol(sf::VideoMode(800,600, 32), "GOL", sf::Style::Resize);

	gol.run();

	return 0;
}
