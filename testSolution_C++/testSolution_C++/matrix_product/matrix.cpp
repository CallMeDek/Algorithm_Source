#include <fstream>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

Matrix::Matrix() : size(0), _matrix(NULL) {};

Matrix::~Matrix()
{
	if (NULL == _matrix)
	{
		std::cout << "Matrix is empty!! It Cant be deleted..." << std::endl;
		return;
	}

	if (NULL == _array)
	{
		std::cout << "Array is empty!! It Cant be deleted..." << std::endl;
		return;
	}

	delete[] _matrix;
	delete[] _array;
	return;
}

void Matrix::getSizeFromUser()
{
	std::cout << "Please insert the size of array >> ";
	std::cin >> size;
	return;
}

void Matrix::make2DMatrix()
{
	//This line is for creating row space
	_matrix = new (int*[size]);

	//It is for creating column space

	int i = 0;
	for ( ; i < size; i++)
		_matrix[i] = new int[size];

	int k = 0;
	for (i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			_matrix[i][j] = _array[k];
			k++;
		}
	}

	return;
}

void Matrix::printMatrix()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < size; j++)
			std::cout << _matrix[i][j] << " ";
		std::cout << " |";
		std::cout << std::endl;
		
	}

	return;
}

void Matrix::gettingNumbers()
{
	int i = 0;
	_array = new int[(int)pow(size, 2)];

	std::srand(std::time(NULL));
	for (; i < pow(size, 2); i++)
		_array[i] = std::rand() % 9 + 1;

}

void Matrix::execute()
{
	getSizeFromUser();
	gettingNumbers();
	make2DMatrix();
}