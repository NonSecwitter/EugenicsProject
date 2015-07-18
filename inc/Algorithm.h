#ifndef ALGORITHM_H
#define ALGORITHM_H

#include ".\Population.h"
#include ".\Individual.h"

class Algorithm
{
public:
	static Population evolvePopulation(Population pop);

private:
	static const double UNIFORM_RATE;
	static const double MUTATION_RATE;
	static const int	TOURNAMENT_SIZE;
	static const bool	ELITISM;

	static Individual crossOver(Individual &indiv1, Individual &indiv2);
	static void mutate(Individual &indiv);
	static Individual tournamentSelection(Population &pop);


	
};//class Algorithm;

#endif