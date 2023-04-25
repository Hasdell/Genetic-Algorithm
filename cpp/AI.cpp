#include "AI.h"
#include "DoubleBuffering.h"

void AI::CalcPosition()
{
	int value = 0;
	for (int i = 0; i < genes.size(); i+=2)
	{
		if (genes[i] == 0 && genes[i + 1] == 0)
			value = 0;
		else if (genes[i] == 0 && genes[i + 1] == 1)
			value = 1;
		else if (genes[i] == 1 && genes[i + 1] == 0)
			value = 2;
		else if (genes[i] == 1 && genes[i + 1] == 1)
			value = 3;

		switch (value)
		{
		case 0:
			if (gameMap.GetMapVal(position.x, position.y - 1) != 1)
			{
				position.y -= 1;
			}
			break;
		case 1:
			if (gameMap.GetMapVal(position.x + 1, position.y) != 1)
			{
				position.x += 1;
			}
			break;
		case 2:
			if (gameMap.GetMapVal(position.x, position.y + 1) != 1)
			{
				position.y += 1;
			}
			break;
		case 3:
			if (gameMap.GetMapVal(position.x - 1, position.y) != 1)
			{
				position.x -= 1;
			}
			break;
		}
	}
}
void AI::CalcPositionAndDraw()
{
	generation++;
	int value = 0;
	for (int i = 0; i < genes.size(); i += 2)
	{
		if (genes[i] == 0 && genes[i + 1] == 0)
			value = 0;
		else if (genes[i] == 0 && genes[i + 1] == 1)
			value = 1;
		else if (genes[i] == 1 && genes[i + 1] == 0)
			value = 2;
		else if (genes[i] == 1 && genes[i + 1] == 1)
			value = 3;

		switch (value)
		{
		case 0:
			if (gameMap.GetMapVal(position.x, position.y - 1) != 1)
			{
				position.y -= 1;
			}
			break;
		case 1:
			if (gameMap.GetMapVal(position.x + 1, position.y) != 1)
			{
				position.x += 1;
			}
			break;
		case 2:
			if (gameMap.GetMapVal(position.x, position.y + 1) != 1)
			{
				position.y += 1;
			}
			break;
		case 3:
			if (gameMap.GetMapVal(position.x - 1, position.y) != 1)
			{
				position.x -= 1;
			}
			break;
		}
		ChangePosition(position.x, position.y);
		
		if (gameMap.GetTargetYPos() == position.y && gameMap.GetTargetXPos() == position.x)
			break;
	}
	gameMap.Draw();

	generation_String = "Generation : " + to_string(generation);
	fitness_String = "Fitness : " + to_string(fitness);
	distance_String = "Distance : " + to_string(GetDistance());
	
	ScreenPrint(5, MAPSIZE + 2, generation_String.c_str());
	ScreenPrint(5, MAPSIZE + 3, fitness_String.c_str());
	ScreenPrint(5, MAPSIZE + 4, distance_String.c_str());
}
void AI::ChangePosition(int x, int y)
{
	if (gameMap.GetMapVal(x, y) == 0)
	{
		gameMap.SetMapVal(x, y, 3);
	}
}
void AI::Reset()
{
	position.x = 1;
	position.y = 2;
	gameMap.InitMap();
}
void AI::SetBestFitness(double fitness)
{
	this->fitness = fitness;
}
AI* AI::GetInstance()
{
	static AI* instance;
	if (instance == nullptr)
		instance = new AI();
	return instance;
}