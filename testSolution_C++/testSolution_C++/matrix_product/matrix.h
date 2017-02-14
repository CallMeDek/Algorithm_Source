#ifndef MATRIX_HEADER
#define MATRIX_HEADER

/*
Creator: Austine Cheo(Nick name - Dek)
Creation date: 02 / 14 / 2017
Last revision : 02 / 14 / 2017
Revision contents:
1. Creation of this file
*/

class Matrix {
public:
	Matrix();
	virtual ~Matrix();

	//After getting size from user, Make an two-dimentional array
	void make2DArray();

protected:
	int size;
	int** _array;
};

#endif
