#include "GameMap.h"
#include "Population.h"
#include "Chromosome.h"
#include "AI.h"
int main()
{
	srand((unsigned int)time(NULL));

	Population maxone(100, 80, 0.7, 0.04);

	Chromosome bestChrom = maxone.GetBestChromosome();
	int solution = bestChrom.GetChromSize();
	double fittest = bestChrom.GetFitness();

	double crossRate = maxone.GetCrossoverRate();
	
	Chromosome select1(solution);
	Chromosome select2(solution);

	Chromosome child;
	
	while (1)
	{
		int popsize = maxone.GetPopSize();
		for (int i = 0; i < popsize; i+=2)
		{
			double rnd = rand() / (double)RAND_MAX;
			select1 = maxone.Selection();
			select2 = maxone.Selection();
			if (rnd < crossRate)
			{
				maxone.Crossover(select1, select2, child);

				maxone.Mutation(child);

				child.CalcFitness();
			}
			maxone.PushChromToPop(i, child);
		}
		
		maxone.Evaluation();
		maxone.CopyPopToOld();

		bestChrom = maxone.GetBestChromosome();
		maxone.PushChromToPop(bestChrom);

		fittest = bestChrom.GetFitness();

		AI::GetInstance()->SetBestFitness(fittest);
		AI::GetInstance()->Reset();
		AI::GetInstance()->SetGenes(bestChrom.GetChromosome());
		AI::GetInstance()->CalcPositionAndDraw();
		if (AI::GetInstance()->GetDistance() == 0 || AI::GetInstance()->GetGeneration() >= 1000) break;
		// Sleep(1000);
	}
	if (AI::GetInstance()->GetGeneration() < 1000)
		cout << "\n\t\tCongratulation... Find the path" << endl;
	else
		cout << "\n\t\tFailed.. Can't find" << endl;

	return 0;
}
