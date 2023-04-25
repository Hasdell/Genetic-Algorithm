#pragma once
#include "GameMap.h"
#include <vector>
#include <windows.h>
#include <math.h>
#include <string>
class AI
{
	GameMap gameMap;
	Point position;
	vector<int> genes;
	int generation;
	double fitness;
	std::string generation_String;
	std::string fitness_String;
	std::string distance_String;
	AI()
	{
		position.x = 1;
		position.y = 2;
		generation = 0;
		fitness = 0.0;
	}
	~AI()
	{
		if (GetInstance() != nullptr)
			delete GetInstance();
	}
public:
	void Reset();
	void CalcPosition();
	void CalcPositionAndDraw();
	void ChangePosition(int x, int y);
	void Draw() { gameMap.Draw(); }

	int GetDistance()
	{
		return abs(gameMap.GetTargetXPos() - position.x) + abs(gameMap.GetTargetYPos() - position.y);
	}
	int GetGeneration() { return generation; }
	vector<int> GetGenes()
	{
		return genes;
	}
	void SetGenes(vector<int> genes)
	{
		this->genes.resize(genes.size());
		this->genes = genes;
	}
	void SetBestFitness(double fitness);
	static AI* GetInstance();
};

