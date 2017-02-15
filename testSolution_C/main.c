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


int main(void)
{
	int i = 0, j = 0;
	int** identity_mat;

	identity_mat = (int**)malloc(2 * sizeof(int*));

	for( ; j < 2; j++)
		identity_mat[j] = (int*)malloc(2 * sizeof(int));

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (i == j) identity_mat[i][j] = 1;
			else identity_mat[i][j] = 0;
		}
	}

	for (i = 0; i < 2; i++)
	{
		printf("| ");
		for (j = 0; j < 2; j++)
		{
			printf(" %d ", identity_mat[i][j]);
		}
		printf(" |\n");
	}

	free(identity_mat);
	return 0;
}