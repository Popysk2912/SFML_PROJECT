#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class Pointers
{
    static Grid* grid_p; 
    static sf::RenderWindow* window_p;
public:
    static void setGridPointer(Grid* p)
    {
        grid_p = p; 
    }

    static void setWindowPointer(sf::RenderWindow* p)
    {
        window_p = p;
    }

    static Grid* getGridPointer()
    {
        return grid_p;
    }

    static sf::RenderWindow* getWindowPointer()
    {
        return window_p;
    }
};

