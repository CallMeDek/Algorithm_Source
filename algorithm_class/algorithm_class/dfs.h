#pragma once
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node Node;

int node_number(Node*);
void print_nodes(Node*);
Node* merge_sort(Node*);
void update(Node**);
Node* combine(Node*, Node*);

void initVisit(int**, int);
void dfs(int, int**, Node**, int*, int**, int**);

void execute_dfs(void);

void init_clocking(int*, int**, int**, int);
void previsit(int*, int**, int);
void postvisit(int*, int**, int);