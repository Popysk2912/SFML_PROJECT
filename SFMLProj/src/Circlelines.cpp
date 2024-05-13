#include "Circlelines.h"
#include <iostream>

Circlelines::Circlelines()
{
    radius = 250;
    sf::Vertex start = sf::Vertex(sf::Vector2f(0, 0), sf::Color(255, 255, 255));
    for (float i = -30.0f; i <= 30.0f; i += 30.0f)
    {
        lines.push_back(LineOverride(start, radius, i + 90));
    }
}

void Circlelines::draw(sf::RenderTexture* layer)
{
    layer->clear(sf::Color::Transparent);
    for (Line l : lines)
    {
        l.setColor(sf::Color(255, 100, 100));
        layer->draw(l);
    }
    layer->draw(this->getLastVerticies());
}
void Circlelines::update()
{
    for (int i = 0; i < lines.size(); i++)
    {
        lines[i].update();
    }
    
}

void Circlelines::SetPos(sf::Vector2f pos)
{
    position = pos;
    for (int i = 0; i < lines.size(); i++)
    {
        lines[i].setStartPoint(position);
    }
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

