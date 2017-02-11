#include "Combination.h"
#include <iostream>

permutation::permutation(int range) : whole_perm(range), result(1) {}

int permutation::calculate(int size)
{
	if (size == 1) return 1;
	int temp = size;
	return size * calculate(--temp);
}

combination::combination() : whole_comb(0), sub(0), result(1) {}

void combination::setVariables()
{
	std::cout << "Type the number of range for the whole >> ";
	std::cin >> whole_comb;
	std::cout << "Type the number of that which you wanna pick >> ";
	std::cin >> sub;
}