#include <stdio.h>
#include "binarysearch.h"

int binary_search_tree_iterative(int set[], int len, int key)
{
	int start = 0;
	int end = len;
	int middle;
	while (start != end) {
		middle = (start + end) / 2;

		if (set[middle] == key) return middle;
		else if (set[middle] > key) end = middle - 1;
		else start = middle + 1;
	}

	if (set[start] == key) return start;
	else return -1;
}

int binary_serach_tree_recursive(int set[], int start, int end, int key)
{
	if (start == end) {
		if (set[start] == key) return start;
		else return -1;
	}

	int middle = (start + end) / 2;
	if (set[middle] == key) return middle;
	else if (set[middle] > key) return binary_serach_tree_recursive(set, start, middle - 1, key);
	else return binary_serach_tree_recursive(set, middle + 1, end, key);
}

void print_result(int value)
{
	if (value == -1) printf("\nThere's no key you want to find\n");
	else printf("\nWe've just found it at %d \n", value);
}