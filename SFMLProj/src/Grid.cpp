#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	size_x = NULL;
	size_y = NULL;
	grid = std::vector<std::vector<int>>(NULL);

	cell_size = 0;
}

void Grid::initGrid(sf::Vector2i size)
{
	cell_size = 64;
	size_x = size.x;
	size_y = size.y;
	grid.resize(size_y);
	for (int y = 0; y < size_y; y++)
	{
		grid[y].resize(size_x);
	}

	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			grid[x][y] = CellType::Empty;
		}
	}
}
void Grid::draw(sf::RenderTexture* layer)
{
	layer->clear(sf::Color::Transparent);
	sf::Color color;
	for (int x = 0; x < size_x; x++)
	{
		for (int y = 0; y < size_y; y++)
		{
			sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f((float)cell_size - 1, (float)cell_size - 1));
			rect.setPosition(sf::Vector2f((float)x * cell_size - 1 , (float)y * cell_size - 1));
			if (grid[y][x] == CellType::Filled)
			{
				color = sf::Color(255, 255, 255);
			}
			else if (grid[y][x] == CellType::Empty)
			{
				color = sf::Color(55, 55, 55);
			}
			rect.setFillColor(color);
			layer->draw(rect);
		}
	}
}

void Grid::setCell(int x, int y, int value)
{
	grid[y][x] = value;
}

std::vector<std::vector<int>> Grid::getGrid()
{
	return grid;
}
int Grid::getCell(int x, int y)
{
	return grid[y][x];
}
