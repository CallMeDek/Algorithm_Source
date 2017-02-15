#include "product.h"
#include "matrix.h"
#include <iostream>

void Product::simpleProduct(Matrix& producted, Matrix& a, Matrix& b)
{
	for (int i = 0; i < a.getSize(); i++)
	{
		for (int j = 0; j < b.getSize(); j++)
		{
			for (int k = 0; k < b.getSize(); k++)
			{
				producted.getMatrix()[i][j] += a.getMatrix()[i][k] * b.getMatrix()[k][j];
			}
		}
	}
	
}

void Product::setElementsToZero(Matrix& mat)
{
	int i = 0, j = 0;

	while (i < mat.getSize())
	{
		while (j < mat.getSize())
		{
			mat.getMatrix()[i][j] = 0;
			j++;
		}
		i++;
	}

	return;
}

//Matrix& Product::DivideConquerProduct(Matrix& producted, const Matrix& a, const Matrix& b)
//{
//
//}