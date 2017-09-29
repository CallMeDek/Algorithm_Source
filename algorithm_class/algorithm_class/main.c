#include <stdio.h>
#include "tournament.h"
#include "binarysearch.h"

int main(int argc, char** argv) 
{
	////This is for the test of the tournament algorithm.
	//char* teams[] = {"France", "Germany", "Brazil", "Colombia", "Argentina", "Belgium", "Netherlands", "Costarica"};
	//tournament(teams, sizeof(teams) / sizeof(char*));
	//printf("\nThe recursive tournament...\n");
	//printf("The result...\n");
	//printf("The winner is %s !!\n", tournament_recursive(teams, 0, sizeof(teams) / sizeof(char*) - 1));

	//This is for the test of the binary search algorithm.
	int key = 9;
	int set[10] = { 0, 2, 5, 9, 11, 15, 18, 21, 23, 30 };
	int result = binary_serach_tree_recursive(set, 0, sizeof(set) / sizeof(int) - 1, key);
	print_result(result);
	result = binary_search_tree_iterative(set, sizeof(set) / sizeof(int) - 1, key);
	print_result(result);
	key = 31;
	result = binary_serach_tree_recursive(set, 0, sizeof(set) / sizeof(int) - 1, key);
	print_result(result);
	result = binary_search_tree_iterative(set, sizeof(set) / sizeof(int) - 1, key);
	print_result(result);
	return 0;
}



