#include "permutation.h"
#include <iostream>

Permutation::Permutation() : permu_array(NULL), size(0), result(1) {  }

Permutation::~Permutation()
{
	if ( NULL == permu_array)
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

void Permutation::setSize()
{
	getSizeFromUser();
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

void Permutation::calculate(int way)
{
	if (way == 1)
	{
		int j = 0;

		while (j < this->size)
		{
			result *= permu_array[j];
			j++;
		}
	}
	else if (way == 2)
	{ 
		int temp = this->size;
		result = recursiveResult(temp);
	}
	else
		std::cout << "It's worthless option!!" << std::endl;
}

int Permutation::recursiveResult(int _size)
{
	if (_size == 1) return 1;
	int temp = _size;
	return _size * recursiveResult(--temp);
}

void Permutation::printResult()
{
	std::cout << size << "! = " << this->getResult() << "\n";
}

void Permutation::execute(int option)
{
	if (option == 1)
		makePermu_array();
	else if (option == 2)
		setSize();
	calculate(option);
	printResult();
}

//void Permutation::printArray()
//{
//	for (int i = 0; i < size; i++)
//		std::cout << this->permu_array[i] << " ";
//	std::cout << std::endl;
//}