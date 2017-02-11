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
	combination(int, int);
	virtual ~combination();
private:
	//We will pick some elements among the whole
	int whole_comb;
	int sub;
	int result;
};

//We will calculate the combination using this.
class permutation {
	permutation(int);
	virtual ~permutation();
private:
	// whole_perm is range of the permutaion
	int whole_perm;
	int result;
};

#endif
