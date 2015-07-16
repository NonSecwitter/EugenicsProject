#ifndef POPULATION_H
#define POPULATION_H

#include ".\Individual.h"

class Population
{
public:
	Individual *individuals;
	int numIndividuals;

	Population(int populationSize, bool initialize);
	~Population();

	Individual getIndividual(int index);
	Individual getFittest();

	int size();

	void saveIndividual(int index, Individual indiv);
}; //class Population;


#endif