#ifndef COMBINATION_HEADER
#define COMBINATION_HEADER

/*
Creator: Austine Cheo(Nick name - Dek)
Creation date: 02 / 11 / 2017
Last revision : 02 / 11 / 2017
Revision contents:
1. Creation of this file
*/

class combination {
public:
	combination();
	virtual ~combination();

	//Setting 'whole_comb', 'sub' through what the user will type for this process
	void setVariables();

	//Starting the calculation
	void calculation();

	//Creating an object and return the result 
	int getPermutation(int);

private:
	//We will pick some elements among the whole
	int whole_comb;
	int sub;
	int result;
};

//We will calculate the combination using this.
class permutation {
public:
	permutation(int);
	virtual ~permutation();
	int calculate(int);

	int getWhole_perm() { return whole_perm; }
private:
	// whole_perm is range of the permutaion
	int whole_perm;
	int result;
};

#endif
