#pragma once
#include "AI.h"
#include <vector>
using namespace std;
class Chromosome
{
	vector<int> genes;
	int chromSize;
	double fitness;
	double fitnessRate;
public:
	Chromosome(int size = 80) { ResetChromosome(size); }
	~Chromosome() {}

	void ResetChromosome(int size);
	void InitChromosome();

	int GetChromSize() { return chromSize; }
	double GetFitness() { return fitness; }
	double GetFitnessRate() const { return fitnessRate; }
	vector<int> GetChromosome() { return genes; }

	void SetFitness(double fr) { fitness = fr; }
	void SetFitnessRate(double rt) { fitnessRate = rt; }
	void SetChromosome(vector<int> genes) { this->genes = genes; }

	void CalcFitness();
};

