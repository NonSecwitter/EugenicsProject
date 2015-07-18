#include "..\inc\FitnessCalc.h"

byte *FitnessCalc::solution = new byte{ '\0' };
int FitnessCalc::solutionLength = 0;

void FitnessCalc::setSolution(byte *newSolution, int newSolutionLength)
{
	solution = new byte[newSolutionLength];
	solutionLength = newSolutionLength;

	for (int i = 0; i < newSolutionLength; i++)
	{
		solution[i] = newSolution[i];
	}
}

void FitnessCalc::setSolution(std::string newSolution)
{
	solutionLength = newSolution.length();
	solution = new byte[solutionLength];

	for (int i = 0; i < solutionLength; i++)
	{
		solution[i] = newSolution[i];
	}
}

int FitnessCalc::getFitness(Individual &indiv)
{
	int fitness = 0;

	for (int i = 0; i < indiv.size() && i < solutionLength; i++)
	{
		if (indiv.getGene(i) == solution[i])
		{
			fitness++;
		}
	}
	return fitness;
}
int FitnessCalc::getMaxFitness()
{
	int maxFitness = solutionLength;
	return maxFitness;
}