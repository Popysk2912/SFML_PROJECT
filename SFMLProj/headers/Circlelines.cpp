#include "Circlelines.h"
#include <iostream>

Circlelines::Circlelines()
{
    radius = 250;
    for (float i = 0.0f; i < 360.0f; i += 1.0f)
    {
        sf::Vertex start = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 255, 255));
        lines.push_back(LineOverride(start, radius, i));
    }
}

void Circlelines::draw(sf::RenderWindow& window)
{
    for (Line l : lines)
        window.draw(l);
    window.draw(this->getLastVerticies());
}
void Circlelines::update()
{
    for (int i = 0; i < lines.size(); i++)
    {
        lines[i].setStartPoint(position);
        lines[i].setStartPoint(position);
    }
}

void Circlelines::SetPos(sf::Vector2f pos)
{
    position = pos;
}

sf::VertexArray Circlelines::getLastVerticies()
{
    sf::VertexArray arr;
    arr.setPrimitiveType(sf::LinesStrip);
    for(int i = 0; i < lines.size(); i++)
    {
        arr.append(lines[i].getEndPoint());
    }
    arr.append(lines[0].getEndPoint());

    return arr;
}

void Circlelines::printpos()
{
    std::cout << "X:" << position.x << " ";
    std::cout << "Y:" << position.y << std::endl;
}

