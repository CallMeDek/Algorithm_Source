#include <stdio.h>

/*
These are for the divide and conquer
#include "tournament.h"
#include "binarysearch.h"
#include "mergesort.h"
#include "quicksort.h"
#include "common.h"
#include "median.h"
#include "multiplication.h"
#include "matrixmultiplication.h"*/

//#include "dfs.h"
#include "bfs.h"

int main(int argc, char** argv) 
{
	////This is for the test of the tournament algorithm.
	//char* teams[] = {"France", "Germany", "Brazil", "Colombia", "Argentina", "Belgium", "Netherlands", "Costarica"};
	//tournament(teams, sizeof(teams) / sizeof(char*));
	//printf("\nThe recursive tournament...\n");
	//printf("The result...\n");
	//printf("The winner is %s !!\n", tournament_recursive(teams, 0, sizeof(teams) / sizeof(char*) - 1));

	////This is for the test of the binary search algorithm.
	//int key = 9;
	//int set[10] = { 0, 2, 5, 9, 11, 15, 18, 21, 23, 30 };
	//int result = binary_serach_tree_recursive(set, 0, sizeof(set) / sizeof(int) - 1, key);
	//print_result(result);
	//result = binary_search_tree_iterative(set, sizeof(set) / sizeof(int) - 1, key);
	//print_result(result);
	//key = 31;
	//result = binary_serach_tree_recursive(set, 0, sizeof(set) / sizeof(int) - 1, key);
	//print_result(result);
	//result = binary_search_tree_iterative(set, sizeof(set) / sizeof(int) - 1, key);
	//print_result(result);

	////This is for the test of the multiplication algorithm
	//int num1, num2;
	//printf("Insert two numbers>>");
	//scanf("%d %d", &num1, &num2);
	//printf("%d x %d = %d\n", num1, num2, multiply(num1, num2));

	////This is for the test of the merge sorting algorithm
	//int arr[10] = { 5, 7, 9, 14, 1, 2, 4, 3, 23, 5 };
	//printArr(0, sizeof(arr) / sizeof(int) - 1, arr);
	//merge_sort(0, sizeof(arr) / sizeof(int) - 1, arr);
	//printArr(0, sizeof(arr) / sizeof(int) - 1, arr);

	////This is for the test of the quick sorting algorithm
	//int arr[10] = { 5, 7, 9, 14, 1, 2, 4, 3, 23, 5 };
	//printArr(0, sizeof(arr) / sizeof(int) - 1, arr);
	//quick_sort(0, sizeof(arr) / sizeof(int) - 1, arr);
	//printArr(0, sizeof(arr) / sizeof(int) - 1, arr);

	////This is for the test of the median algorithm
	//int arr[10] = { 5, 7, 9, 14, 1, 2, 4, 3, 23, 5 };
	//printf("%d th element of the set is %d...\n", 6, median(6, 0, sizeof(arr) / sizeof(int) - 1, arr));
	
	////This is for the test of the matrix multiplication algorithm
	//int X[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	//int Y[4][4] = { { 1,0,0,0 },{ 0,1,0,0 },{ 0,0,1,0 },{ 0,0,0,1 } };
	//int Z[4][4] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
	//int W[4][4] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };

	////allocateEle(X, sizeof(X) / sizeof(X)[0]);
	////allocateEle(Y, sizeof(X) / sizeof(X)[0]);
	//bruteForceMultiply(X, Y, Z, sizeof(X) / sizeof(X)[0]);
	//print2DArr(Z, sizeof(X) / sizeof(X)[0]);

	//bestMultiply(X, Y, W, sizeof(X) / sizeof(X)[0]);
	//print2DArr(W, sizeof(X) / sizeof(X)[0]);
	
	////This is for the test of dfs algorithm
	//execute_dfs();

	//This is for the test of bfs algorithm
	execute_bfs();

	return 0;
}

/*
 Input:
 4 5 (number of vertices, number of edges)

 1 2
 1 3
 1 4
 2 4
 3 4
*/








