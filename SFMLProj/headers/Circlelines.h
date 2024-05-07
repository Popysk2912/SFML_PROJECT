#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Line.h"




class Circlelines
{
private:
	sf::Vector2f position = sf::Vector2f(0, 0);
	std::vector<LineOverride> lines;
	float radius;
	

public:
	Circlelines(const std::vector<std::vector<int>>& grid);
	void printpos();

	void draw(sf::RenderWindow& window);
	void update();

	void SetPos(sf::Vector2f pos);

	sf::VertexArray getLastVerticies();
};

