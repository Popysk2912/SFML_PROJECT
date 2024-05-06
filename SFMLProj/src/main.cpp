#include <SFML/Graphics.hpp>
#include "Circlelines.h"
#include "Grid.h"

#include <iostream>
#include<math.h>

void print2dVector(const std::vector<std::vector<int>>& vec);

int main()
{   
    sf::RenderWindow window(sf::VideoMode(640, 640), "SFML");
    Circlelines circle = Circlelines();
    Grid g = Grid();
    g.initGrid(sf::Vector2i(10, 10));
    g.setCell(1, 2, CellType::Filled);
    print2dVector(g.getGrid());

 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        circle.SetPos((sf::Vector2f)(sf::Mouse::getPosition(window)));

        window.clear(sf::Color(0, 0, 0));
        g.draw(window);
        circle.draw(window);
        window.display();
    }

    return 0;
}

void print2dVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}