#include <iostream>
#include "permutation.h"

int main(void)
{
	Permutation a;
	a.getSizeFromUser();

	std::cout << a.getSize() << std::endl;

	return 0;
}