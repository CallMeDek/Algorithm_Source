#include "dfs.h"

void execute_dfs(void)
{
	int n, m, u, v;
	int i, j, clock, for_forest, for_scc;
	int* visited;
	int* prev;
	int* post;
	int** forest;
	int* strongly_connected_component;
	Node** heads;
	Node** pp;
	Node* temp;

	printf("Input:\n");
	scanf_s("%d %d", &n, &m);
	printf("\n");
	heads = (Node**)calloc(n, sizeof(Node*));

	for (i = 0; i < n; i++)
	{
		heads[i] = (Node*)malloc(sizeof(Node));
		(heads[i])->data = i + 1;
		(heads[i])->next = NULL;
	}

	pp = (Node**)calloc(n, sizeof(Node*));
	for (i = 0; i < n; i++)
		pp[i] = heads[i];

	i = 0;
	while (i < m)
	{
		scanf_s("%d %d", &u, &v);
		temp = (Node*)malloc(sizeof(Node));
		temp->data = v;
		temp->next = NULL;
		(pp[u - 1])->next = temp;
		(pp[u - 1]) = (pp[u - 1])->next;
		temp = NULL;

		temp = (Node*)malloc(sizeof(Node));
		temp->data = u;
		temp->next = NULL;
		(pp[v - 1])->next = temp;
		(pp[v - 1]) = (pp[v - 1])->next;
		temp = NULL;
		i++;
	}

	pp = heads;
	for (i = 0; i < n; i++)
		update(&pp[i]);

	heads = pp;

	pp = heads;
	for (i = 0; i < n; i++)
		print_nodes(pp[i]);
	initVisit(&visited, n);

	pp = heads;
	init_clocking(&clock, &prev, &post, n);
	init_forest(&forest, n, &for_forest);
	printf("(Start!) -> ");
	for (i = 0; i < n; i++)
	{
		strongly_connected_component = (int*)calloc(n, sizeof(int));
		for_scc = 0;
		if (!visited[i]) dfs(i + 1, &visited, pp, &clock, &prev, &post, &strongly_connected_component, &for_scc);
		forest[for_forest++] = strongly_connected_component;
		strongly_connected_component = NULL;
	}
	printf(" -> (The end)\n");

	for (i = 0; i < n; i++)
		printf(" %d (%d, %d) ", i+1, prev[i], post[i]);
	printf("\n");

	i = 0;
	for_forest--;
	while (i < for_forest)
	{
		if (forest[i][0] == 0){
			i++;
			continue;
		}
		j = 0;
		printf("Strongly connected component %d : ", i + 1);
		while (j < n)
		{
			if (forest[i][j] == 0)
			{
				j++;
				continue;
			}
			printf("%d ", forest[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void update(Node** head)
{
	Node* h = (*head);
	h = merge_sort(h->next);
	(*head)->next = h;
}

Node* merge_sort(Node* head)
{
	if (head == NULL || head->next == NULL) return head;
	Node* h = head;
	Node* a; Node* b;
	int midpoint, i;

	a = h; b = h;
	midpoint = node_number(h) / 2;

	for (i = 0; i < midpoint; i++)
		b = b->next;

	for (i = 0; i < midpoint - 1; i++)
		a = a->next;
	a->next = NULL;
	a = h;

	a = merge_sort(a);
	b = merge_sort(b);
	h = combine(a, b);
	return h;
}

Node* combine(Node* a, Node* b)
{
	Node* result;
	Node* h;
	Node* temp;
	Node* aa = a;
	Node* bb = b;

	result = (Node*)malloc(sizeof(Node));

	if (aa->data <= bb->data)
	{
		result->data = aa->data;
		result->next = aa->next;
		aa = aa->next;
	}
	else
	{
		result->data = bb->data;
		result->next = bb->next;
		bb = bb->next;
	}

	h = result;
	while (aa != NULL && bb != NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (aa->data <= bb->data)
		{
			temp->data = aa->data;
			temp->next = aa->next;
			h->next = temp;
			aa = aa->next;
		}
		else
		{
			temp->data = bb->data;
			temp->next = bb->next;
			h->next = temp;
			bb = bb->next;
		}
		h = h->next;
		temp = NULL;
	}

	h;
	while (aa != NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->data = aa->data;
		temp->next = aa->next;
		h->next = temp;
		aa = aa->next;
		h = h->next;
		temp = NULL;
	}

	while (bb != NULL)
	{
		temp = (Node*)malloc(sizeof(Node));
		temp->data = bb->data;
		temp->next = bb->next;
		h->next = temp;
		bb = bb->next;
		h = h->next;
		temp = NULL;
	}
	return result;
}

int node_number(Node* node)
{
	if (node->next == NULL) return 1;
	return 1 + node_number(node->next);
}

void print_nodes(Node* head)
{
	if (head == NULL) return;

	if (head->next == NULL)
	{
		printf("%d \n", head->data);
		return;
	}
	printf("%d ", head->data);
	print_nodes(head->next);
}

void initVisit(int** visited, int node_num)
{
	(*visited) = (int*)calloc(node_num, sizeof(int));
	for (int i = 0; i < node_num; i++)
		(*visited)[i] = 0;
}

void dfs(int node, int** visited, Node** heads, int* clock, int** prev, int** post, int** scc, int* counter_scc)
{
	int i;
	Node* head = heads[node-1];

	if ((*visited)[node - 1]) {
		return;
	}
	printf("%d ", node);

	(*scc)[(*counter_scc)++] = node;
	(*visited)[node - 1] = 1;

	previsit(clock, prev, node);
	for (i = 0; i < node_number(heads[node - 1]) - 1; i++)
	{
		dfs(head->next->data, visited, heads, clock, prev, post, scc, counter_scc);
		head = head->next;
	}
	postvisit(clock, post, node);
}

void init_clocking(int* clock, int** prev, int** post, int num)
{
	*clock = 0;
	(*prev) = (int*)calloc(num, sizeof(int));
	(*post) = (int*)calloc(num, sizeof(int));
}

void previsit(int* clock, int** prev,  int node)
{
	*clock = *clock + 1;
	(*prev)[node - 1] = *clock;
}

void postvisit(int* clock, int** post, int node) 
{
	*clock = *clock + 1;
	(*post)[node - 1] = *clock;
}

void init_forest(int*** forest, int n, int* for_forest)
{
	(*forest) = (int**)calloc(n, sizeof(int*));
	*for_forest = 0;
}