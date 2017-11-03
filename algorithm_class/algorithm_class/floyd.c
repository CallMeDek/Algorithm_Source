#include "floyd.h"

void execute_floyd(void)
{

	int n;
	int** adjacency_matrix;
	int** dist;

	init(&n, &adjacency_matrix);
	print_mat(adjacency_matrix, n);

	dist = floyd(adjacency_matrix, n);
	print_mat(dist, n);
}

void init(int* n, int*** adj_mat)
{
	int i, j;
	int e;
	int u, v, w;

	puts("Input:");
	scanf("%d %d", n, &e);
	puts(" ");

	(*adj_mat) = (int**)calloc(*n, sizeof(int*));

	for (i = 0; i < *n; i++)
		(*adj_mat)[i] = (int*)calloc(*n, sizeof(int));

	for (i = 0; i < *n; i++)
	{
		for (j = 0; j < *n; j++)
		{
			if (i == j)
				(*adj_mat)[i][j] = 0;
			else
				(*adj_mat)[i][j] = 100;
		}
	}

	i = 0;
	while (i < e)
	{
		scanf("%d %d %d", &u, &v, &w);
		(*adj_mat)[u - 1][v - 1] = w;
		i++;
	}


}

void print_mat(int** mat, int len)
{
	int i, j;

	puts(" ");
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			printf("%d ", mat[i][j]);
		puts(" ");
	}
}

int** floyd(int** adj_mat, int len)
{
	int i, j, k;
	int** dist;

	dist = make_dist_mat(adj_mat, len);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			for (k = 0; k < len; k++)
			{
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	return dist;
}

int** make_dist_mat(int** adj_mat, int len)
{
	int i, j;
	int** dist;

	dist = (int**)calloc(len, sizeof(int*));
	for (i = 0; i < len; i++)
		dist[i] = (int*)calloc(len, sizeof(int));

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			dist[i][j] = adj_mat[i][j];
			j++;
		}

		i++;
	}

	puts(" ");
	return dist;
}
