#include "GameMap.h"
#include "DoubleBuffering.h"
#include <iostream>
using namespace std;

void GameMap::InitMap()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			map[y][x] = 0;

			if (y == 0 || y == height-1)
			{
				map[y][x] = 1;
			}
			if (x == 0 || x == width-1)
			{
				map[y][x] = 1;
			}
			if (y == 3 && x < 5)
			{
				map[y][x] = 1;
			}
			if (y == 3 && x >= width-10)
			{
				map[y][x] = 1;
			}
			if (y == 6 && x < 9)
			{
				map[y][x] = 1;
			}
			if (y == 6 && x >= width - 8)
			{
				map[y][x] = 1;
			}
			if (y == 6 && x < 4)
			{
				map[y][x] = 1;
			}
			if (y == 12 && x < 10)
			{
				map[y][x] = 1;
			}
			if (y == 12 && x >= width - 5)
			{
				map[y][x] = 1;
			}
			if (y == targetPosition.y && x == targetPosition.x)
			{
				map[y][x] = 2;
			}
			if (y == 2 && x == 1)
			{
				map[y][x] = 2;
			}
		}
	}
}
int GameMap::GetWidth()
{
	return width;
}
int GameMap::GetHeight()
{
	return height;
}
int GameMap::GetMapVal(int x, int y)
{
	return map[y][x];
}

void GameMap::SetMapVal(int x, int y, int value)
{
	map[y][x] = value;
}

void GameMap::Draw()
{
	ScreenClear();

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (map[y][x] == 0)
				ScreenPrint(x, y, " ");
			if (map[y][x] == 1)
				ScreenPrint(x, y, "0");
			if (map[y][x] == 2)
				ScreenPrint(x, y, "s");
			if (map[y][x] == 3)
				ScreenPrint(x, y, "x");
		}
		cout << '\n';
	}

}