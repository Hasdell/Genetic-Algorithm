#include "Chromosome.h"

void Chromosome::ResetChromosome(int size)
{
	chromSize = size;
	fitness = 0.0f;
	fitnessRate = 0.0f;
	genes.resize(size);
	InitChromosome();
}

void Chromosome::InitChromosome()
{
	double rnd;

	for (int i = 0; i < chromSize; i++)
	{
		rnd = rand() / (double)RAND_MAX;

		genes[i] = rnd >= 0.5 ? 1 : 0;
	}
	CalcFitness();
}

void Chromosome::CalcFitness()
{
	fitness = 0.0f;

	AI::GetInstance()->Reset();
	AI::GetInstance()->SetGenes(genes);
	AI::GetInstance()->CalcPosition();

	fitness = 1 / ((double)AI::GetInstance()->GetDistance() + 1);
}
