#include <stdio.h>
#include "median.h"
#include "common.h"

int median(int k, int start, int end, int set[])
{
	if (start >= end) return set[start + k];

	int middle = partition(start, end, set);

	if (middle < k) median(k - middle, middle + 1, end, set);
	else if (middle > k) median(k, start, middle - 1, set);
	else return set[middle];
}

int partition(int start, int end, int set[])
{
	int s = start + 1, e = end;
	while (s <= e)
	{
		while ((set[e] >= set[start]) && (s <= e)) e--;
		while ((set[s] <= set[start]) && (s <= e)) s++;

		if (s <= e) swap(&set[s], &set[e]);
	}

	swap(&set[start], &set[e]);
	return e;
}