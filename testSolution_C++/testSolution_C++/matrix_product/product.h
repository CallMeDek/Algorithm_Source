#ifndef PRODUCT_HEADER
#define PRODUCT_HEADER

#include "matrix.h"

class Product {
	
	//This function just conduct matrix product with easiest way we know
	Matrix& simpleProduct(Matrix&, const Matrix&, const Matrix&);

	//It is for conducting fast product
	Matrix& DivideConquerProduct(Matrix&, const Matrix&, const Matrix&);
};

#endif
