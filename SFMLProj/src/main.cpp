#include <SFML/Graphics.hpp>
#include "Circlelines.h"
#include "Grid.h"


#include "debugFuncs.h"

#include "Pointers.h"

#include <iostream>
#include <vector>
#include<math.h>


int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML");
    Pointers::setWindowPointer(&window);

    Grid g = Grid();
    Pointers::setGridPointer(&g);

    Circlelines circle = Circlelines();

    g.initGrid(sf::Vector2i(10, 10));    


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

        window.display();
    }

    return 0;
}