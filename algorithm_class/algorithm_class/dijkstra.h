#pragma once
#include <stdio.h>
#include <stdlib.h>

/*
for dijkstra
Input:
5 9 (# of vertices, # of edges)

1 2 4
1 3 2
2 3 3
2 4 2
2 5 3
3 2 1
3 4 4
3 5 5
5 4 1

*/

void execute_dijkstra(void);

void init(int***, int*, int*);
void print_mat(int **, int);
void dijkstra(int, int, int**, int**, int**);

void init_dist_prev(int**, int**, int);
void init_node_list(int**, int**, int);
void modify_list(int**, int, int);
int is_empty(int*, int);
void print_list(int*, int);

void including_into_selected(int**, int, int);

int get_min(int**, int**, int*, int*, int);
int is_included(int*, int, int);

int** create_result_mat(int*, int);

void print_result(int**, int*, int);
void print_path(int**, int);

