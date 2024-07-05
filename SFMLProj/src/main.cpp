#include <iostream>
#include <SFML/Graphics.hpp>

#include "debugFuncs.h"
#include "Pointers.h"
#include "DrawBatch.h"


int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML");
    Pointers::setWindowPointer(&window);
    DrawBatch::initLayers(10);
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        DrawBatch::draw(window);
        window.display();
    }
    DrawBatch::deleteLayers();
    return 0;
}