#ifndef FITNESSCALC_H
#define FITNESSCALC_H

#include ".\Individual.h"
#include <string>

typedef unsigned char byte;

class FitnessCalc
{
public:
	FitnessCalc();
	static void setSolution(byte *newSolution, int newSolutionLength);
	static void setSolution(std::string newSolution);
	static int  getFitness(Individual &indiv);
	static int  getMaxFitness();

private:
	static byte *solution;
	static int solutionLength;



};//class FitnessCalc;
#endif
