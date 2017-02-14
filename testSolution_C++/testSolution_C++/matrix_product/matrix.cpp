#include <fstream>
#include <iostream>
#include "matrix.h"

Matrix::Matrix() : size(0), _array(NULL) {};

Matrix::~Matrix()
{
	if (NULL == _array)
	{
		std::cout << "Array is empty!! It Cant be deleted..." << std::endl;
		return;
	}

	delete[] _array;
	return;
}

void Matrix::getSizeFromUser()
{
	std::cout << "Please insert the size of array >> ";
	std::cin >> size;
	return;
}

void Matrix::make2DArray()
{
	//This line is for creating row space
	_array = new (int*[size]);

	//It is for creating column space
	for (int i = 0; i < size; i++)
		_array[i] = new int[size];

	return;
}