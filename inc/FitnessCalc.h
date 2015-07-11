#ifndef FITNESSCALC_H
#define FITNESSCALC_H

#include <string>

class FitnessCalc
{
public:
	static void setSolution(unsigned int *newSolution);
	static void setSolution(std::string newSolution);
	static int  getFitness(Individual indiv);
	static int  getMaxFitness();

private:
	unsigned int solution[64];



};//class FitnessCalc;
#endif
