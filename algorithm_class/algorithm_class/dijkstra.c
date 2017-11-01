#include "dijkstra.h"

void execute_dijkstra(void)
{
	int** adjacency_matrix_weight; int** result_mat;
	int* dist; int* prev;
	int n, e;

	init(&adjacency_matrix_weight, &n, &e);
	//print_mat(adjacency_matrix_weight, n);

	dijkstra(n, 0, &dist, &prev, adjacency_matrix_weight);
	result_mat = create_result_mat(prev, n);
	print_result(result_mat, dist, n);
}

void init(int*** adj_mat, int* n, int* e)
{
	int i, j;
	int u, v, w;

	puts("Input:");
	scanf_s("%d %d", n, e);
	(*adj_mat) = (int**)calloc(*n, sizeof(int*));
	puts(" ");

	for (i = 0; i < *n; i++)
		(*adj_mat)[i] = (int*)calloc(*n, sizeof(int));

	for (i = 0; i < *n; i++)
	{
		for (j = 0; j < *n; j++)
			(*adj_mat)[i][j] = -1;
	}


	i = 0;
	while (i < *e)
	{
		scanf_s("%d %d %d", &u, &v, &w);
		(*adj_mat)[u - 1][v - 1] = w;
		i++;
	}
}

void print_mat(int ** mat, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			printf("%d ", mat[i][j]);
		puts(" ");
	}

}

void dijkstra(int node_num, int start, int** dist, int** prev, int** weight_mat)
{
	int i;
	int now, next;
	int* node_list;
	int* selected;

	init_dist_prev(dist, prev, node_num);

	for (i = 0; i < node_num; i++)
	{
		(*dist)[i] = 10000; // It must be a reasonably large number
		(*prev)[i] = -1;
	}

	init_node_list(&node_list, &selected, node_num);
	(*dist)[start] = 0;

	while (!is_empty(node_list, node_num))
	{
		now = get_min(weight_mat, &node_list, selected, *dist, node_num);
		including_into_selected(&selected, node_num, now);
		for (i = 0; i < node_num; i++)
		{
			if (weight_mat[now][i] == -1) continue;
			next = i;
			if ((*dist)[next] >(*dist)[now] + weight_mat[now][next])
			{
				(*dist)[next] = (*dist)[now] + weight_mat[now][next];
				(*prev)[next] = now;
			}
		}
	}
}

void init_dist_prev(int** dist, int** prev, int len)
{
	(*dist) = (int*)calloc(len, sizeof(int));
	(*prev) = (int*)calloc(len, sizeof(int));
}

void init_node_list(int** list, int** selected, int len)
{
	int i;

	(*list) = (int*)calloc(len, sizeof(int));
	(*selected) = (int*)calloc(len, sizeof(int));

	i = 0;
	while (i < len)
	{
		(*selected)[i] = -1;
		(*list)[i] = i;
		i++;
	}
}

void modify_list(int** list, int data, int len)
{
	int i, j;
	i = 0;
	while (i < len)
	{
		if ((*list)[i] == data)
		{
			j = i;
			while (j < len - 1)
			{
				(*list)[j] = (*list)[j + 1];
				j++;
			}
			(*list)[len - 1] = -1;
			break;
		}
		i++;
	}
}

int is_empty(int* list, int len)
{
	int result = 1;
	for (int i = 0; i < len; i++)
	{
		if (list[i] != -1)
			result = 0;
	}
	return result;
}

int get_min(int** weight_mat, int** list, int* selected, int* dist, int len)
{
	int node = 0;
	int min_dist = 100000; //It must be a reasonably large number.
	int i;


	for (i = 0; i < len; i++)
	{
		if ((!is_included(selected, len, i)) && (min_dist > dist[i]))
		{
			node = i;
			min_dist = dist[i];
		}
	}

	modify_list(list, node, len);
	return node;
}

int is_included(int* selected, int len, int node)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (selected[i] == node) return 1;
	}
	return 0;
}

void including_into_selected(int** selected, int len, int node)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if ((*selected)[i] == -1)
		{
			(*selected)[i] = node;
			break;
		}
	}
}

int** create_result_mat(int* prev, int len)
{
	int i;
	int** mat;

	mat = (int**)calloc(2, sizeof(int*));
	for (i = 0; i < 2; i++)
		mat[i] = (int*)calloc(len, sizeof(int));

	for (i = 0; i < len; i++)
	{
		mat[0][i] = i;
		mat[1][i] = prev[i];
	}

	return mat;
}

void print_result(int** result_mat, int* dist, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d's path : ", i + 1);
		print_path(result_mat, i);
		printf(" | and minimum cost is %d\n", dist[i]);
	}
}

void print_path(int** result_mat, int index)
{
	if (result_mat[1][index] == -1) {
		printf("%d ", result_mat[0][index] + 1);
		return;
	}
	print_path(result_mat, result_mat[1][index]);
	printf("%d ", result_mat[0][index] + 1);
}

void print_list(int* list, int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d ", list[i]);
	printf("\n");
}