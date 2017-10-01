#include <stdio.h>
#include "quicksort.h"

void quick_sort(int start, int end, int set[])
{
	if (start >= end) return;
	int middle = divide(start, end, set);
	quick_sort(start, middle - 1, set);
	quick_sort(middle + 1, end, set);
}

int divide(int start, int end, int set[])
{
	int s = start + 1, e = end;
	while (s <= e)
	{
		while ((set[e] >= set[start]) && (s <= e)) e--;
		while ((set[s] < set[start]) && (s <= e)) s++;

		if (s < e) swap(&set[s], &set[e]);
	}

	swap(&set[e], &set[start]);
	return e;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

