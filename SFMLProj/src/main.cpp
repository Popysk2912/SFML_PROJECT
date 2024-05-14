#include <SFML/Graphics.hpp>
#include "Circlelines.h"
#include "Grid.h"

#include "debugFuncs.h"

#include "Pointers.h"
#include "DrawBatch.h"

#include <iostream>

#define gridLayer 0
#define playerLayer 2
#define layoutLayer 1




int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML");
    Pointers::setWindowPointer(&window);
    DrawBatch::initLayers(10);

    Grid g = Grid();    
    g.initGrid(sf::Vector2i(10, 10));
    Pointers::setGridPointer(&g);

    Circlelines circle = Circlelines();
 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        circle.SetPos((sf::Vector2f)sf::Mouse::getPosition(window));
        circle.update();

        circle.draw(DrawBatch::getLayer(playerLayer));
        g.draw(DrawBatch::getLayer(gridLayer));

        DrawBatch::draw(window);
        window.display();
    }
    DrawBatch::clearLayers();
    return 0;
}