#include "..\inc\Individual.h"
#include "..\inc\FitnessCalc.h"
#include <chrono>
#include <random>

int Individual::DEFAULT_GENE_LENGTH = 11;

Individual::Individual()
{
	genes = new byte[DEFAULT_GENE_LENGTH];

	fitness = 0;
}

void Individual::generateIndividual()
{
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine randomGenerator(seed);

	for (int i = 0; i < size(); i++)
	{
		byte gene = randomGenerator() % 58 + 65;
		genes[i] = gene;
	}
}

void Individual::setDefaultGeneLength(int length)
{
	DEFAULT_GENE_LENGTH = length;
}

byte Individual::getGene(int index)
{
	return genes[index];
}

void Individual::setGene(int index, byte value)
{
	genes[index] = value;
	fitness = 0;
}

int Individual::size()
{
	return DEFAULT_GENE_LENGTH;
}

int Individual::getFitness()
{
	
	if (fitness == 0)
	{
		fitness = FitnessCalc::getFitness(*this);
	}
	return fitness;
}


std::string Individual::toString()
{
	std::string geneString = "";
	for (int i = 0; i < size(); i++)
	{
		geneString += (char)getGene(i);
	}
	return geneString;
}

Individual::~Individual()
{
	//delete [] genes;
}

