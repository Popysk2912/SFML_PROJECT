#pragma once
#include "CellTypes.h"

#include <vector>
#include <SFML/Graphics.hpp>


class Grid
{
private:
	int size_x;
	int size_y;
	std::vector<std::vector<int>> grid;
public:
	int cell_size;

	Grid();

	void initGrid(sf::Vector2i size);
	void draw(sf::RenderWindow& window);

	std::vector<std::vector<int>> getGrid();
	int getCell(int x, int y);

	void setCell(int x, int y, int value);
};

