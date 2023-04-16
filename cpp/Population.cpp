#include "Population.h"

Population::Population(int popSize, int chromSize, double cRate, double mRate)
{
	this->popSize = popSize;
	this->chromSize = chromSize;
	crossoverRate = cRate;
	mutationRate = mRate;
	population.resize(popSize);
	oldPop.resize(popSize);
	for (int i = 0; i < popSize; i++)
		population[i].ResetChromosome(chromSize);
	Evaluation();
	CopyPopToOld();
}

Chromosome Population::Selection()
{
	int selectIndex = 0;
	double rnd = rand() / (double)RAND_MAX;
	double setRate = 0.0;
	for (int i = 0; i < popSize; i++)
	{
		setRate += oldPop[i].GetFitnessRate();
		if (setRate >= rnd)
		{
			selectIndex = i;
			break;
		}
	}

	return oldPop[selectIndex];
}

void Population::Crossover(Chromosome& chrom1, Chromosome& chrom2, Chromosome& child)
{
	int crossPoint = rand() % chromSize;

	child.ResetChromosome(chrom1.GetChromSize());
	child.SetChromosome(chrom1.GetChromosome());

	for (int i = 0; i < crossPoint; i++)
	{
		child.GetChromosome()[i] = chrom2.GetChromosome()[i];
	}
}

void Population::Mutation(Chromosome& chrom)
{
	double rnd = rand() / (double)RAND_MAX;
	if (rnd < mutationRate)
		return;

	int mutatePoint = rand() % chromSize;
	vector<int> genes = chrom.GetChromosome();
	genes[mutatePoint] = 1 - genes[mutatePoint];

	chrom.SetChromosome(genes);
}

void Population::Evaluation()
{
	totalFitness = 0;
	int bestChromIndex = 0;

	double bestFitness = 0;

	for (int i = 0; i < popSize; i++)
	{
		population[i].CalcFitness();
		double curChromFit = population[i].GetFitness(); // i번째 크로모좀의 fitness
		if (curChromFit > bestFitness) // Find Best Chrom
		{
			bestChromIndex = i;
			bestFitness = curChromFit;
		}
		totalFitness += curChromFit;
	}
	// 각 Chromosome의 FitnessRate 계산
	for (int i = 0; i < popSize; i++)
	{
		double curFitRate = population[i].GetFitness() / totalFitness;
		population[i].SetFitnessRate(curFitRate);
	}
	bestChromosome = population[bestChromIndex];
}

void Population::CopyPopToOld()
{
	for (int i = 0; i < popSize; i++)
		oldPop[i] = population[i];
}
void Population::PushChromToPop(int index, Chromosome chrom)
{
	population[index] = chrom;
}
void Population::PushChromToPop(Chromosome chrom)
{
	for (int i = 0; i < popSize; i++)
		population[i] = chrom;
}