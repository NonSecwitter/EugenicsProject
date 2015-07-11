#include "..\inc\Population.h"

Population::Population(int populationSize, bool initialize)
{
	individuals = new Individual[populationSize];

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

void Population::saveIndividual(int index, Individual indiv)
{
	individuals[index] = indiv;
}