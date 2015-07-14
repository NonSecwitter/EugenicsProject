#include ".\inc\FitnessCalc.h"
#include ".\inc\Population.h"
#include ".\inc\Algorithm.h"
#include <iostream>

int main()
{
	FitnessCalc::setSolution("Hello World");

	Population myPop(50, true);

	int generationCount = 0;

	while (myPop.getFittest().getFitness() < FitnessCalc::getMaxFitness())
	{
		generationCount++;
		std::cout << "Generation: " << generationCount << std::endl
				  << "Fittest: " << myPop.getFittest().getFitness();
		myPop = Algorithm::evolvePopulation(myPop);
	}

	std::cout << "Solution Found!" << std::endl
		<< "Generation: " << generationCount << std::endl
		<< "Genes: " << myPop.getFittest().toString();


	return 0;
}