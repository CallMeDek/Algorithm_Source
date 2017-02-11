#ifndef PERMUTATION_HEADER
#define PERMUTATION_HEADER

/*
Creator: Austine Cheo(Nick name - Dek)
Creation date: 02 / 11 / 2017
Last revision : 02 / 11 / 2017
Revision contents:
1. Creation of this file
*/

class Permutation {

public:
	Permutation();
	virtual ~Permutation();

	//Receiving the size of permutaion from the user
	void getSizeFromUser();

private:
	//Making a array for obtaining the permutation
	//you can get it by multiplying all elements of this array
	int* permu_array;
	int size;

};

#endif
