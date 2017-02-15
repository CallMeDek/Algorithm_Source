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

void makeIdentityMatrix();
void printMatrix(int**, int);

int main(void)
{
	makeIdentityMatrix();
	printMatrix(identity_mat, 2);

	free(identity_mat);
	return 0;
}

void makeIdentityMatrix()
{
	int i = 0, j = 0;
	identity_mat = (int**)malloc(2 * sizeof(int*));

	for (; j < 2; j++)
		identity_mat[j] = (int*)malloc(2 * sizeof(int));

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
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