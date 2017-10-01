#include <stdio.h>
#include "tournament.h"
#include "binarysearch.h"
#include "mergesort.h"
#include "quicksort.h"

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
	//printf("두 수 입력>>");
	//scanf("%d %d", &num1, &num2);
	//printf("%d x %d = %d\n", num1, num2, multiplication(num1, num2));

	////This is for the test of the merge sorting algorithm
	//int arr[10] = { 5, 7, 9, 14, 1, 2, 4, 3, 23, 5 };
	//printArr(0, sizeof(arr) / sizeof(int) - 1, arr);
	//merge_sort(0, sizeof(arr) / sizeof(int) - 1, arr);
	//printArr(0, sizeof(arr) / sizeof(int) - 1, arr);

	//This for the test of the quick sorting algorithm
	int arr[10] = { 5, 7, 9, 14, 1, 2, 4, 3, 23, 5 };
	printArr(0, sizeof(arr) / sizeof(int) - 1, arr);
	quick_sort(0, sizeof(arr) / sizeof(int) - 1, arr);
	printArr(0, sizeof(arr) / sizeof(int) - 1, arr);
	return 0;
}



