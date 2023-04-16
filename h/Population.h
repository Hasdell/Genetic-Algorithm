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

	//genetic algorithm ������
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
	void CopyPopToOld(); // ���� ���븦 �θ𼼴�� �����
	void PushChromToPop(int index, Chromosome chrom); // �����ϴ� ���
	void PushChromToPop(Chromosome chrom);
};

