#include "matrixmultiplication.h"

void print2DArr(int arr[][4], int len)
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void allocateEle(int(*arr)[4], int len)
{
	int i, j;

	srand(time(NULL));
	i = 0; j = 0;
	while (i < len)
	{
		while (j < len)
		{
			arr[i][j] = rand() % 20 + 1;
			j++;
		}
		i++;
		j = 0;
	}
}

void bruteForceMultiply(int a[][4], int b[][4], int(*c)[4], int len)
{
	int i, j, k;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			for (k = 0; k < len; k++)
				c[i][j] += (a[i][k] * b[k][j]);
		}
	}
}

void _multiply(int*** a, int*** b, int*** c, int len)
{
	int i, j, k;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			for (k = 0; k < len; k++)
				(*c)[i][j] += ((*a)[i][k] * (*b)[k][j]);
		}
	}
}

void addition(int*** a, int*** b, int*** c, int len, int flag)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++) {
			if (flag) (*c)[i][j] = (*a)[i][j] + (*b)[i][j];
			else (*c)[i][j] = (*a)[i][j] - (*b)[i][j];
		}
	}
}

void make2DArr(int*** a, int len)
{
	int i;
	*a = (int**)calloc(len, sizeof(int*));
	for (i = 0; i < len; i++)
		(*a)[i] = (int*)calloc(len, sizeof(int));
}

void extract(int a[][4], int*** b, int len, int row, int col)
{
	int i, j;
	int r = row, c = col;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			(*b)[i][j] = a[r][c++];
		c = col;
		r++;
	}
}

void combine(int** leftUp, int** rightUp, int** leftDown, int** rightDown, int(*e)[4], int len)
{
	int i, j, k, l;
	for (i = 0; i < len / 2; i++)
	{
		for (j = 0; j < len / 2; j++)
			e[i][j] = leftUp[i][j];
	}

	for (i = 0; i < len / 2; i++)
	{
		for (j = len / 2, k = 0; j < len; j++, k++)
			e[i][j] = rightUp[i][k];
	}

	for (i = len / 2, k = 0; i < len; i++, k++)
	{
		for (j = 0; j < len; j++)
			e[i][j] = leftDown[k][j];
	}

	for (i = len / 2, k = 0; i < len; i++, k++)
	{
		for (j = len / 2, l = 0; j < len; j++, l++)
			e[i][j] = rightDown[k][l];
	}
}

void bestMultiply(int a[][4], int b[][4], int(*c)[4], int len)
{
	int** p1; int** p2; int** p3; int** p4; int** p5; int** p6; int** p7;
	int** temp1; int** temp2; int** partition1; int** partition2;
	int** clause1; int** clause2; int** clause3; int** clause4;

	make2DArr(&p1, len / 2); make2DArr(&p2, len / 2); make2DArr(&temp1, len / 2);
	make2DArr(&p3, len / 2); make2DArr(&p4, len / 2); make2DArr(&temp2, len / 2);
	make2DArr(&p5, len / 2); make2DArr(&p6, len / 2); make2DArr(&p7, len / 2);
	make2DArr(&partition1, len / 2); make2DArr(&partition2, len / 2);
	make2DArr(&clause1, len / 2); make2DArr(&clause2, len / 2); make2DArr(&clause3, len / 2);
	make2DArr(&clause4, len / 2);

	extract(b, &partition1, len / 2, 0, len / 2);
	extract(b, &partition2, len / 2, len / 2, len / 2);
	addition(&partition1, &partition2, &temp1, len / 2, 0);
	extract(a, &partition1, len / 2, 0, 0);
	_multiply(&partition1, &temp1, &p1, len / 2);

	extract(a, &partition1, len / 2, 0, 0);
	extract(a, &partition2, len / 2, 0, len / 2);
	addition(&partition1, &partition2, &temp1, len / 2, 1);
	extract(b, &partition1, len / 2, len / 2, len / 2);
	_multiply(&temp1, &partition1, &p2, len / 2);

	extract(a, &partition1, len / 2, len / 2, 0);
	extract(a, &partition2, len / 2, len / 2, len / 2);
	addition(&partition1, &partition2, &temp1, len / 2, 1);
	extract(b, &partition1, len / 2, 0, 0);
	_multiply(&temp1, &partition1, &p3, len / 2);

	extract(b, &partition1, len / 2, len / 2, 0);
	extract(b, &partition2, len / 2, 0, 0);
	addition(&partition1, &partition2, &temp1, len / 2, 0);
	extract(a, &partition1, len / 2, len / 2, len / 2);
	_multiply(&partition1, &temp1, &p4, len / 2);

	extract(a, &partition1, len / 2, 0, 0);
	extract(a, &partition2, len / 2, len / 2, len / 2);
	addition(&partition1, &partition2, &temp1, len / 2, 1);
	extract(b, &partition1, len / 2, 0, 0);
	extract(b, &partition2, len / 2, len / 2, len / 2);
	addition(&partition1, &partition2, &temp2, len / 2, 1);
	_multiply(&temp1, &temp2, &p5, len / 2);

	extract(a, &partition1, len / 2, 0, len / 2);
	extract(a, &partition2, len / 2, len / 2, len / 2);
	addition(&partition1, &partition2, &temp1, len / 2, 0);
	extract(b, &partition1, len / 2, len / 2, 0);
	extract(b, &partition2, len / 2, len / 2, len / 2);
	addition(&partition1, &partition2, &temp2, len / 2, 1);
	_multiply(&temp1, &temp2, &p6, len / 2);

	extract(a, &partition1, len / 2, 0, 0);
	extract(a, &partition2, len / 2, len / 2, 0);
	addition(&partition1, &partition2, &temp1, len / 2, 0);
	extract(b, &partition1, len / 2, 0, 0);
	extract(b, &partition2, len / 2, 0, len / 2);
	addition(&partition1, &partition2, &temp2, len / 2, 1);
	_multiply(&temp1, &temp2, &p7, len / 2);

	addition(&p5, &p4, &temp1, len / 2, 1);
	addition(&temp1, &p2, &temp2, len / 2, 0);
	addition(&temp2, &p6, &clause1, len / 2, 1);

	addition(&p1, &p2, &clause2, len / 2, 1);

	addition(&p3, &p4, &clause3, len / 2, 1);

	addition(&p1, &p5, &temp1, len / 2, 1);
	addition(&temp1, &p3, &temp2, len / 2, 0);
	addition(&temp2, &p7, &clause4, len / 2, 0);

	combine(clause1, clause2, clause3, clause4, c, len);

	free(partition1); free(partition2); (temp1); free(temp2);
	free(p1); free(p2); free(p3); free(p4); free(p5); free(p6); free(p7);
	free(clause1); free(clause2); free(clause3); free(clause4);
}