#pragma once
#include <vector>
#include <SFML/Graphics.hpp>


class Grid
{
private:
	int size_x;
	int size_y;

public:
	std::vector<std::vector<int>> grid;
	Grid();
	void initGrid(sf::Vector2i size);
};

