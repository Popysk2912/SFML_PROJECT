#include <SFML/Graphics.hpp>
#include "Circlelines.h"
#include "Grid.h"

#include "debugFuncs.h"

#include "Pointers.h"
#include "DrawBatch.h"



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

        circle.draw(DrawBatch::getLayer(2));
        g.draw(DrawBatch::getLayer(0));


        DrawBatch::draw(window);
        window.display();
    }

    return 0;
}