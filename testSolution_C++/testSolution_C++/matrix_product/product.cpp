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
				//producted.getMatrix()[i][j] += a.getMatrix()[i][k] * b.getMatrix()[k][j];
				std::cout << producted.getMatrix()[i][j] << std::endl;
			}
		}
	}
	
}

//Matrix& Product::DivideConquerProduct(Matrix& producted, const Matrix& a, const Matrix& b)
//{
//
//}