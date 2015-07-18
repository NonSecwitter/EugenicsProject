#include "..\inc\Population.h"
#include <iostream>

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
			std::cout << "New " << i << ": " << newIndividual.toString() << std::endl;
			std::cout << "Saved " << i << ": " << getIndividual(i).toString() << std::endl;
		}
	}
}

Individual Population::getIndividual(int index)
{
	Individual gottenIndiv = individuals[index];
	return gottenIndiv;
}

Individual Population::getFittest()
{
	Individual fittest = individuals[0];
	int fittestFitness = fittest.getFitness();

	Individual competitor;
	int competitorFitness = 0;

	for (int i = 1; i < size(); i++)
	{
		competitor = getIndividual(i);
		competitorFitness = competitor.getFitness();

		if (fittestFitness <= getIndividual(i).getFitness())
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

Population::Population(const Population &other)
{
	numIndividuals = other.numIndividuals;
	individuals = new Individual[numIndividuals];

	for (int i = 0; i < size(); i++)
	{
		individuals[i] = other.individuals[i];
	}
}

Population& Population::operator=(const Population &rhs)
{
	numIndividuals = rhs.numIndividuals;
	individuals = new Individual[numIndividuals];

	for (int i = 0; i < size(); i++)
	{
		individuals[i] = rhs.individuals[i];
	}

	return *this;
}
