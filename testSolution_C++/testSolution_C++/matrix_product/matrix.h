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
	void make2DMatrix();

	void getSizeFromUser();

	//To show the elements of matrix;
	void printMatrix();

	//the numbers will be used as elements
	void gettingNumbers();

	int getSize() const { return size; }
	int** getMatrix() { return _matrix; }

private:
	int size;
	int* _array;
	int** _matrix;
};

#endif
