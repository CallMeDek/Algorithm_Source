#include <stdio.h>
#include <stdlib.h>

/*
Creator: Austine Cheo(Nick name - Dek)
Creation date: 02 / 11 / 2017
Last revision : 02 / 11 / 2017
Revision contents:
1. Creation of this file
*/

//This solution is created for implementing involution of matrix

int** test_mat;
int** identity_mat;
int** result_mat;

//For creating an identity matrix
void makeIdentityMatrix(int);

//For creating a N-dimentional matrix
int** make2DMatrix(int);
void printMatrix(int**, int);

//To seek the answer with recursive function
int** pow(int**, int, int);
int** product(int**, int**, int);
int main(void)
{
	makeIdentityMatrix(2);
	printMatrix(identity_mat, 2);

	test_mat = make2DMatrix(2);
	test_mat[0][0] = 1;
	test_mat[0][1] = 2;
	test_mat[1][0] = 3;
	test_mat[1][1] = 4;

	result_mat = pow(test_mat, 2, 4);
	printMatrix(result_mat, 2);

	free(identity_mat);
	return 0;
}

int** make2DMatrix(int size)
{
	int** mat;

	mat = (int**)malloc(size * sizeof(int*));

	for (int i = 0; i < size; i++)
	{
		mat[i] = (int*)malloc(size * sizeof(int));
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;
	}

	return mat;
	
}

void makeIdentityMatrix(int size)
{
	int i = 0, j = 0;
		
	identity_mat = make2DMatrix(size);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j) identity_mat[i][j] = 1;
			else identity_mat[i][j] = 0;
		}
	}
}

void printMatrix(int** mat, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		printf("| ");
		for (j = 0; j < size; j++)
		{
			printf(" %d ", mat[i][j]);
		}
		printf(" |");
		if (j == size - 1) return;
		printf("\n");
	}
}

int** product(int** a, int** b, int size)
{
	int** temp;
	temp = make2DMatrix(size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
				temp[i][j] += a[i][k] * b[k][j];
		}
	}

	return temp;
}

int** pow(int** mat, int size, int count)
{
	if (count == 1) return identity_mat;
	if (count % 2 == 1) return product(mat, pow(mat, size, count--), size);
	return product(pow(mat, size, count / 2), pow(mat, size, count / 2), size);
}