#include "bfs.h"

void execute_bfs(void)
{
	int n, e;
	int* visited;
	int** adjacency_mat;

	init(&n, &e, &adjacency_mat);
	//print_mat(&adjacency_mat, n);
	start_bfs(n, &visited, adjacency_mat);

}

void init(int* node_num, int* edge_num, int*** adjacency_matrix)
{
	int i, u, v;

	puts("Input:");
	scanf_s("%d %d", node_num, edge_num);
	puts(" ");

	(*adjacency_matrix) = (int**)calloc((*node_num), sizeof(int*));
	for (i = 0; i < (*node_num); i++)
		(*adjacency_matrix)[i] = (int*)calloc((*node_num), sizeof(int));

	i = 0;
	while (i < (*edge_num))
	{
		scanf_s("%d %d", &u, &v);
		(*adjacency_matrix)[u - 1][v - 1] = 1;
		(*adjacency_matrix)[v - 1][u - 1] = 1;
		i++;
	}
}

void init_visited(int** visited, int len)
{
	(*visited) = (int*)calloc(len, sizeof(int));
}

void print_mat(int*** adjacency_mat, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			printf("%d ", (*adjacency_mat)[i][j]);
		printf("\n");
	}
}

int start_bfs(int node_num, int** visited, int** adj_mat)
{
	int i;

	init_visited(visited, node_num);

	printf("start! -> ");
	for (i = 0; i < node_num; i++)
	{
		if (!(*visited)[i]) bfs(i, visited, adj_mat, node_num);
	}
	printf("The end..\n");
	return 1;
}
void bfs(int start, int** visited, int** adj_mat, int node_num)
{
	int* queue;
	int front, rear;
	int now, next;
	int i;

	make_queue(&queue, &front, &rear, node_num * 2);

	enqueue(node_num * 2, start, front, &rear, &queue);
	while (!is_empty(front, rear, node_num * 2))
	{
		now = peek(node_num * 2, front, rear, &queue);
		dequeue(node_num * 2, rear, &front, &queue);

		if (now == -1) break;

		printf("%d -> ", now + 1);

		(*visited)[now] = 1;
		for (i = 0; i < node_num; i++)
		{
			next = adj_mat[now][i];
			if (!next) continue;
			if (!(*visited)[i])
			{
				(*visited)[i] = 1;
				enqueue(node_num * 2, i, front, &rear, &queue);
			}
		}
	}
}

void make_queue(int** queue, int* front, int* rear, int len)
{
	(*queue) = (int*)calloc(len, sizeof(int));
	(*front) = 0;
	(*rear) = 0;

	for (int i = 0; i < len; i++)
		(*queue)[i] = -1;
}

int is_full(int front, int rear, int node_num)
{
	if ((rear + 1) % node_num == front) return 1;
	else return 0;
}
int is_empty(int front, int rear, int node_num)
{
	if (front % node_num == rear) return 1;
	else return 0;
}

int enqueue(int node_num, int node, int front, int* rear, int** queue)
{
	if (is_full(front, (*rear), node_num)) return -1;
	(*queue)[(*rear) % node_num] = node;
	(*rear)++;
	return 1;
}

int dequeue(int node_num, int rear, int* front, int** queue)
{
	if (is_empty((*front), rear, node_num)) return -1;
	(*queue)[(*front) % node_num] = -1;
	(*front)++;
	return 1;
}

int peek(int node_num, int front, int rear, int** queue)
{
	if (is_empty(front, rear, node_num)) return -1;
	return (*queue)[front % node_num];
}

int length_linked_vertex(int node_num, int node, int** adj_mat)
{
	if (node_num == 0) return 0;

	if (adj_mat[node][node_num - 1]) return 1 + length_linked_vertex(--node_num, node, adj_mat);
	else return 0 + length_linked_vertex(--node_num, node, adj_mat);
}

void print_queue(int* queue, int len)
{
	if (len == 0) return;
	int x = len;
	print_queue(queue, --len);
	printf("%d ", queue[x]);
}