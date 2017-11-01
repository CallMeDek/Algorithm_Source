#pragma once
#include <stdio.h>
#include <stdlib.h>

void execute_bfs(void);

void init(int*, int*, int***);
void init_visited(int**, int);
void make_queue(int**, int*, int*, int);
void print_mat(int***, int);
int length_linked_vertex(int, int, int**);
int start_bfs(int, int**, int**);
void bfs(int, int**, int**, int);

int is_full(int, int, int);
int is_empty(int, int, int);
int enqueue(int, int, int, int*, int**);
int dequeue(int, int, int*, int**);
int peek(int, int, int, int**);
void print_queue(int*, int);