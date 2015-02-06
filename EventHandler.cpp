#include "EventHandler.hpp"

bool EventHandler::pollWindowEvents()
{
	while (WorldWindow.pollEvent(WindowEvent))
	{
        switch (WindowEvent.type)
        {
        case sf::Event::Resized:
            //win_size = Window.getSize();
            break;
        case sf::Event::Closed:
            World.quit();
            break;
        case sf::Event::MouseButtonPressed:
        case sf::Event::MouseMoved:
            handleMouse();
            break;
        case sf::Event::KeyPressed:
            handleKeyboard();
            break;
        default:
            break;
        }
    }

    return true;
}

bool EventHandler::handleMouse()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        mouse_pos = sf::Mouse::getPosition(WorldWindow);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
    {
    }

    return true;
}

bool EventHandler::handleKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        World.quit();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
    {
        World.toggleVsync();
    }

    return true;
}
