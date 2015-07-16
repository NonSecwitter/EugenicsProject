#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H


#include <string>

typedef unsigned char byte;

class Individual
{
public:
	Individual();
	~Individual();
	static int  DEFAULT_GENE_LENGTH;
	static void setDefaultGeneLength(int length);

	void generateIndividual();
	
	void setGene(int index, byte value);
	byte getGene(int index);

	int size();

	int getFitness();

	std::string toString();

private:

	byte *genes;

	int fitness;

};//class Individual;


#endif