#ifndef FITNESSCALC_H
#define FITNESSCALC_H

#include <string>

typedef unsigned char byte;

class FitnessCalc
{
public:
	static void setSolution(byte *newSolution);
	static void setSolution(std::string newSolution);
	static int  getFitness(Individual *indiv);
	static int  getMaxFitness();

private:
	byte solution[64];



};//class FitnessCalc;
#endif
