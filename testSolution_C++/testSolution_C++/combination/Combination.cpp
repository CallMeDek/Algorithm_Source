#include "Combination.h"

permutation::permutation(int range) : whole_perm(range), result(1) {}

int permutation::calculate(int size)
{
	if (size == 1) return 1;
	int temp = size;
	return size * calculate(--temp);
}