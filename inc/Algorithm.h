#ifndef ALGORITHM_H
#define ALGORITHM_H

#include ".\Population.h"
#include ".\Individual.h"

class Algorithm
{
public:
	static Population evolvePopulation(Population pop);

private:
	const double UNIFORM_RATE = 0.5;
	const double MUTATION_RATE = 0.015;
	const int	 TOURNAMENT_SIZE = 5;
	const bool	 ELITISM = true;

	static Individual crossOver(Individual indiv1, Individual indiv2);
	static void mutate(Individual indiv);
	static Individual tournamentSelection(Population pop);


	
};//class Algorithm;

#endif