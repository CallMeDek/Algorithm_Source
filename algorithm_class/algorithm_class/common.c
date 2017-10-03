#include <stdio.h>
#include "common.h"

void print_result(int value)
{
	if (value == -1) printf("\nThere's no key you want to find\n");
	else printf("\nWe've just found it at %d \n", value);
}

void printArr(int start, int end, int set[])
{
	if (start == end) printf("%d \n", set[start]);
	else {
		printf("%d ", set[start]);
		printArr(start + 1, end, set);
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}