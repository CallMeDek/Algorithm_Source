#include "product.h"
#include "matrix.h"

Matrix& Product::simpleProduct(Matrix& producted, Matrix& a, Matrix& b)
{
	for (int i = 0; i < a.getSize(); i++)
	{
		for (int j = 0; j < b.getSize(); j++)
		{
			for (int k = 0; k < b.getSize(); k++)
				producted.getMatrix()[i][j] = a.getMatrix()[i][k] * b.getMatrix()[k][j];
		}
	}

	return producted;
}

//Matrix& Product::DivideConquerProduct(Matrix& producted, const Matrix& a, const Matrix& b)
//{
//
//}