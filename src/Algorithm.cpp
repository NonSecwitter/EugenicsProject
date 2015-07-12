#include "..\inc\Algorithm.h"
#include <random>
#include <chrono>

unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine randomGenerator(seed);

const double Algorithm::UNIFORM_RATE = 0.5;
const double Algorithm::MUTATION_RATE = 0.015;
const int	 Algorithm::TOURNAMENT_SIZE = 5;
const bool	 Algorithm::ELITISM = true;

Population Algorithm::evolvePopulation(Population pop)
{
	Population newPopulation(pop.size(), false);

	if (ELITISM)
	{
		newPopulation.saveIndividual(0, pop.getFittest());
	}

	int elitismOffset;
	if (ELITISM)
	{
		elitismOffset = 1;
	}
	else
	{
		elitismOffset = 0;
	}

	for (int i = elitismOffset; i < pop.size(); i++)
	{
		Individual indiv1 = tournamentSelection(pop);
		Individual indiv2 = tournamentSelection(pop);
		Individual newIndiv = crossOver(indiv1, indiv2);
		newPopulation.saveIndividual(i, newIndiv);
	}

	for (int i = elitismOffset; i < newPopulation.size(); i++)
	{
		mutate(newPopulation.getIndividual(i));
	}

	return newPopulation;
}

Individual Algorithm::crossOver(Individual indiv1, Individual indiv2)
{
	Individual newSol;

	for (int i = 0; i < indiv1.size(); i++)
	{
		if (((randomGenerator() % 100) / 100) <= UNIFORM_RATE)
		{
			newSol.setGene(i, indiv1.getGene(i));
		}
		else
		{
			newSol.setGene(i, indiv2.getGene(i));
		}
	}
}












