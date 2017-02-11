#include "permutation.h"
#include <iostream>

Permutation::Permutation() : permu_array(nullptr), size(0) {  }

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