#pragma once

#include <stdio.h>
#include <stdlib.h>

/*
for floyd
Input: 
3 5 (# of vertices, # of edges)

1 2 4
1 3 11
2 1 6
2 3 2
3 1 3
*/

void init(int*, int***);
void print_mat(int**, int);

int** floyd(int**, int);
int** make_dist_mat(int**, int);

void execute_floyd(void);
