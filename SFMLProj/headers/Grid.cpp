#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	size_x = NULL;
	size_y = NULL;
	grid = std::vector<std::vector<int>>(0);
}

void Grid::initGrid(sf::Vector2i size)
{
	size_x = size.x;
	size_y = size.y;
	std::cout << "Not initialized " << sizeof(grid) << std::endl;
	grid.resize(size_y);
	for (int y = 0; y < grid.size(); y++)
	{
		grid[y].resize(size_x);
	}

	for (int y = 0; y < grid.size(); y++)
	{
		for (int x = 0; x < grid[y].size(); x++)
		{
			grid[x][y] = 1;
		}
	}
	std::cout << "Initialized " << sizeof(grid) << std::endl;
}