#include "permutation.h"
#include <iostream>

Permutation::Permutation() : permu_array(nullptr), size(0) {  }

Permutation::~Permutation()
{
	if (permu_array == nullptr) 
	{ 
	  std::cout << "This array is Null!!" << std::endl; 
	  return; 
	}

	delete[] permu_array;
	return;
}

