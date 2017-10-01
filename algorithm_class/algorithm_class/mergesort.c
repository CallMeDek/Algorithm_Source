#include <stdio.h>
#include "mergesort.h"

void merge_sort(int start, int end, int set[])
{
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(start, middle, set);
		merge_sort(middle + 1, end, set);
		merge(start, middle, end, set);
	}
}

void merge(int start, int middle, int end, int set[])
{
	int i;
	int left_start = start, left_end = middle, right_start = middle + 1, right_end = end;
	int count = 0;
	int* temp = (int*)calloc(end - start + 1, sizeof(int));
	while ((left_start <= left_end) && (right_start <= right_end))
	{
		if (set[left_start] < set[right_start]) temp[count++] = set[left_start++];
		else temp[count++] = set[right_start++];
	}
	while (left_start <= left_end) temp[count++] = set[left_start++];
	while (right_start <= right_end) temp[count++] = set[right_start++];

	count = 0;
	for (i = start; i <= end; i++)
		set[i] = temp[count++];
	free(temp);
}

void printArr(int start, int end, int set[])
{
	if (start == end) printf("%d \n", set[start]);
	else {
		printf("%d ", set[start]);
		printArr(start + 1, end, set);
	}
}