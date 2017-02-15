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

int test_mat[2][2] = { { 1, 2 },{ 3, 4 } };
int** identity_mat;
int** result_mat;

//For creating an identity matrix
void makeIdentityMatrix(int);

//For creating a N-dimentional matrix
void make2DMatrix(int***, int);
void printMatrix(int**, int);

int main(void)
{
	makeIdentityMatrix(2);
	printMatrix(identity_mat, 2);

	free(identity_mat);
	return 0;
}

void make2DMatrix(int*** mat, int size)
{
	int k = 1;

	*mat = (int**)malloc(size * sizeof(int*));
	
	for (int i = 0; i < size; i++)
	{
		(*mat)[i] = (int*)malloc(size * sizeof(int));
	}
	
}

void makeIdentityMatrix(int size)
{
	int i = 0, j = 0;
		
	make2DMatrix(&identity_mat, size);

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