#ifndef FAST_SUM_HEADER
#define FAST_SUM_HEADER

/*
Creator: Austine Cheo(Nick name - Dek)
Creation date: 02 / 13 / 2017
Last revision : 02 / 13 / 2017
Revision contents:
1. Creation of this file
*/

/*
	Basic idea of this algorithm is as follows

	if size is even number, 
		fastSum of n = 1 + 2 + 3 + ... + n
					 = 1 + 2 + 3 + ... + ( n / 2 ) + ( n / 2 + 1 ) + ... + n
					 = fastSum of (n / 2) + ( n / 2 + 1 ) + ... + n
					 = fastSum of (n / 2) + ( n / 2 + 1 ) + ( n / 2 + 2 ) + ( n / 2 + 3 ) + ... ( n / 2 + n / 2)
					 = fastSum of (n / 2) + ( n / 2 ) * ( n / 2 ) + fastSum of (n / 2)
					 = 2 * fastSum of (n / 2) + ( n^2 / 4 )
	else if size is odd number,
		fastSum of n = fastSum of (n - 1) + n
*/

class FastSum {


};

#endif