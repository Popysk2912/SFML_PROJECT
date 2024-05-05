#include <SFML/Graphics.hpp>
#include "Circlelines.h"
#include "Grid.h"

#include <iostream>
#include<math.h>

void printVector(const std::vector<std::vector<int>>& vec);

int main()
{   
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
    Circlelines circle = Circlelines();
    Grid g = Grid();
    g.initGrid(sf::Vector2i(10, 10));
    printVector(g.grid);
 
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
        circle.draw(window);
        window.display();
    }

    return 0;
}

void printVector(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}