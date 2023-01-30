#pragma once
#include <SFML/Graphics.hpp>
#include "Stack.h"

class BaseWindow
{
public:
    sf::Font font;
    sf::RenderWindow *win = nullptr;
};