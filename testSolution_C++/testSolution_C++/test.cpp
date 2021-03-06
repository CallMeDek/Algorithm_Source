#include <iostream>
#include "matrix_product\matrix.h"
#include "matrix_product\product.h"

int main(void)
{
	Matrix a;
	Matrix b;
	Matrix c;

	a.execute();
	b.execute();
	c.execute();

	a.printMatrix();
	std::cout << "---------------- \n";
	b.printMatrix();

	Product one;
	one.setElementsToZero(c);
	one.simpleProduct(c, a, b);
	c.printMatrix();
	std::cout << "---------------- \n";

	return 0;
}