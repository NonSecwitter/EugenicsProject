#include "..\inc\Population.h"

Population::Population(int populationSize, bool initialize)
{
	individuals = new Individual[populationSize];
	numIndividuals = populationSize;

	if (initialize)
	{
		for (int i = 0; i < size(); i++)
		{
			Individual newIndividual;
			newIndividual.generateIndividual();
			saveIndividual(i, newIndividual);
		}
	}
}

Individual Population::getIndividual(int index)
{
	return individuals[index];
}

Individual Population::getFittest()
{
	Individual fittest = individuals[0];

	for (int i = 0; i < size(); i++)
	{
		if (fittest.getFitness() <= getIndividual(i).getFitness())
		{
			fittest = getIndividual(i);
		}
	}
	return fittest;
}

int Population::size()
{
	return numIndividuals;
}

void Population::saveIndividual(int index, Individual indiv)
{
	individuals[index] = indiv;
}

Population::~Population()
{
	delete[] individuals;
}