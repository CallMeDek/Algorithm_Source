#include <iostream>
#include "permutation.cpp"

int main(int argc, char** argv)
{
	Permutation a;
	a.getSizeFromUser();

	std::cout << a.getSize() << std::endl;

	return 0;
}