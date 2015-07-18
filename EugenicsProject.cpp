#include ".\inc\FitnessCalc.h"
#include ".\inc\Population.h"
#include ".\inc\Algorithm.h"
#include <iostream>

int main()
{
	FitnessCalc::setSolution("hello");

	Population myPop(50, true);

	for (int i = 0; i < myPop.size(); i++)
		std::cout << "Recalled " << i << ": " << myPop.getIndividual(i).toString() << std::endl;

	int generationCount = 0;


	while (myPop.getFittest().getFitness() < FitnessCalc::getMaxFitness())
	{
		generationCount++;
		std::cout << "Generation: " << generationCount << '\t'
				  << "Fitness Level: " << myPop.getFittest().toString() << std::endl;
		myPop = Algorithm::evolvePopulation(myPop);
	}

	std::cout << "Solution Found!" << std::endl
		<< "Generation: " << generationCount << std::endl
		<< "Genes: " << myPop.getFittest().toString();

	std::cin.get();
	return 0;
}