#ifndef PRODUCT_HEADER
#define PRODUCT_HEADER

#include "matrix.h"

class Product {
public:
	void setElementsToZero(Matrix&);

	//This function just conduct matrix product with easiest way we know
	void simpleProduct(Matrix&, Matrix&, Matrix&);

	//It is for conducting fast product
	Matrix& DivideConquerProduct(Matrix&, const Matrix&, const Matrix&);
};

#endif
