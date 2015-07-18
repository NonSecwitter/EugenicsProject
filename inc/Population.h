#ifndef POPULATION_H
#define POPULATION_H

#include ".\Individual.h"

class Population
{
public:


	Population(int populationSize, bool initialize);
	~Population();
	Population(const Population &other);

	Population& operator=(const Population &rhs);

	Individual *individuals;
	int numIndividuals;

	Individual getIndividual(int index);
	Individual getFittest();

	int size();

	void saveIndividual(int index, Individual indiv);
}; //class Population;


#endif