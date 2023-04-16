#pragma once
#include <iostream>
using namespace std;
#define MAPSIZE 20

struct Point
{
	int x;
	int y;
};
class GameMap
{
	int** map;
	int width;
	int height;
	Point targetPosition;
public:
	GameMap()
	{
		height = MAPSIZE;
		width = MAPSIZE;

		targetPosition.x = 5;
		targetPosition.y = 18;

		map = new int* [MAPSIZE];
		for (int i = 0; i < MAPSIZE; i++)
		{
			map[i] = new int[MAPSIZE];
		}
		InitMap();
	}
	~GameMap()
	{
		for (int i = 0; i < MAPSIZE; i++)
		{
			delete map[i];
		}
		delete map;
	}

	void InitMap();

	int GetWidth();
	int GetHeight();
	int GetMapVal(int x, int y);
	int GetTargetXPos() { return targetPosition.x; }
	int GetTargetYPos() { return targetPosition.y; }

	void SetMapVal(int x, int y, int value);

	void Draw();
	void Gotoxy(int x, int y);
};

