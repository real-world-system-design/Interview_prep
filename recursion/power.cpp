#include <iostream>
using namespace std;

/*
T(N) 	= K + T(N-1)
T(N-1)  = K + T(N-2)
T(N-2)  = K + T(N-3)
--------------------
T(N) = SUM_OF I = 1 TILL N K = KN = O(N)


space = O(N)

*/


int power(int a, int n) {
	if(n == 0) {
		return 1;
	}
	return a * power(a, n-1);
} 

/*
Even if it seems that we are doing a logarithmic work 
but we are doing a repeative work and each each time we are making two function calls
*/

int pow_ii(int a, int n) {
	if(n == 0) {
		return 1;
	}
	//rec case
	int halfPowerSquare = pow_ii(a, n/2) * pow_ii(a, n/2);

	if(n%2!=0) {
		return a * halfPowerSquare;
	}
	return halfPowerSquare;
}

/*
Here we are precomputing and making a square operation on that computed value .
*/

int pow_iii(int a, int b) {
	if(n==0) {
		return 1;
	}
	//rec case
	int halfPow = pow_iii(a, n/2);
	int halfPowerSquare = halfPow * halfPow;

	if(n%2!=0) {
		return a * halfPowerSquare;
	}
	return halfPowerSquare;
}

int main() {



	return 0;
}