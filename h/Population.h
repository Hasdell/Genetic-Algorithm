#pragma once
#include "Chromosome.h"
class Population
{
	vector<Chromosome> population;
	vector<Chromosome> oldPop;

	Chromosome bestChromosome;

	int popSize;
	int chromSize;

	double crossoverRate;
	double mutationRate;

	double totalFitness;
public:
	Population(int popSize, int chromSize, double cRate, double mRate);
	~Population() {}

	//genetic algorithm 연산자
	Chromosome Selection();
	void Crossover(Chromosome& gene1, Chromosome& gene2, Chromosome& child);
	void Mutation(Chromosome& gene);
	void Evaluation();

	Chromosome GetBestChromosome() { return bestChromosome; }
	int GetPopSize() { return popSize; }
	int GetChromSize() { return chromSize; }
	double GetCrossoverRate() { return crossoverRate; }
	double GetMutationRate() { return mutationRate; }

	// extra function
	void CopyPopToOld(); // 현재 세대를 부모세대로 만들기
	void PushChromToPop(int index, Chromosome chrom); // 복제하는 기능
	void PushChromToPop(Chromosome chrom);
};

