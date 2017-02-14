#include "fastSum.h"
#include <iostream>
#include <math.h>

FastSum::FastSum(int n) : size(n), result(0) {}

int FastSum::fastSum(int a)
{
	if (a == 1) return 1;

	//if a is odd number, result is fastSum(a-1) -- because (a-1) is an even number --  + n
	if (a % 2 == 1) return fastSum(a - 1) + a;

	int temp = a;

	return 2 * fastSum(a/2) + (pow(a,2.0) / 4);
}

void FastSum::printResult()
{
	std::cout << "The sum is " << result << std::endl;
}

void FastSum::execute()
{
	result = fastSum(size);
	printResult();
}