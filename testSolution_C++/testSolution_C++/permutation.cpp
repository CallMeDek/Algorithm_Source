#include "permutation.h"
#include <iostream>

Permutation::Permutation() : permu_array(nullptr), size(0), result(1) {  }

Permutation::~Permutation()
{
	if (permu_array == nullptr)
	{
		std::cout << "This array is Null!!" << std::endl;
		return;
	}

	delete[] permu_array;
	return;
}

void Permutation::getSizeFromUser()
{
	std::cout << "Input a integer number used for obtain of permutaiton >> ";
	std::cin >> this->size;
	return;
}

void Permutation::makePermu_array()
{
	//Get size in here
	getSizeFromUser();

	//Make the array dynamically
	this->permu_array = new int[size];

	for (int i = 0; i < size; i++)
		permu_array[i] = i + 1;
}

void Permutation::calculate()
{
	int j = 0;

	while (j < this->size)
	{
		result *= permu_array[j];
		j++;
	}
}

void Permutation::printResult()
{
	std::cout << size << "! = " << this->getResult() << "\n";
}

void Permutation::execute()
{
	makePermu_array();
	calculate();
	printResult();
}

//void Permutation::printArray()
//{
//	for (int i = 0; i < size; i++)
//		std::cout << this->permu_array[i] << " ";
//	std::cout << std::endl;
//}