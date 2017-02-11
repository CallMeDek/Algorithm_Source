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

	//Making the array using - void getSizeFromUser() - function
	void makePermu_array();

	//To calculate
	void calculate(int way = 1);

	void printResult();
	int getResult() const { return result; }

	//This function is for executing whole process
	void execute(int option = 1);

	//To get the answer using different method
	int recursiveResult(int _size);

	//Getting size from user if option is 2
	void setSize();

private:
	//Making a array for obtaining the permutation
	//you can get it by multiplying all elements of this array
	int* permu_array;
	int size;
	int result;
};


#endif
