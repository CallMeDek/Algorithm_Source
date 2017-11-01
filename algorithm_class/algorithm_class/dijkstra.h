#pragma once
#include <stdio.h>
#include <stdlib.h>

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