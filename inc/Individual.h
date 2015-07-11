#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include ".\FitnessCalc.h"
#include <string>

class Individual
{
public:
	static const int  DEFAULT_GENE_LENGTH = 64;
	static void setDefaultGeneLength(int length);

	void generateIndividual();
	
	void		 setGene();
	unsigned int getGene(int index);

	int size();

	int getFitness();

	std::string toString();

private:

	unsigned int genes[DEFAULT_GENE_LENGTH];


	int fitness;

};//class Individual;


#endif