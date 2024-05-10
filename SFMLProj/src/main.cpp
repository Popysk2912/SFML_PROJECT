#include <SFML/Graphics.hpp>
#include "Circlelines.h"
#include "Grid.h"

#include "debugFuncs.h"

#include "Pointers.h"
Grid* Pointers::grid_p = nullptr;

#include <iostream>
#include<math.h>


int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML");

    Grid g = Grid();
    Circlelines circle = Circlelines();

    g.initGrid(sf::Vector2i(10, 10));
    
    Pointers::setGridPointer(&g);

    debf::print2dVector(g.getGrid());

 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        circle.SetPos((sf::Vector2f)(sf::Mouse::getPosition(window)));
        circle.update();
        window.clear(sf::Color(0, 0, 0));

        g.draw(window);
        circle.draw(window);

        window.display();
    }

    return 0;
}