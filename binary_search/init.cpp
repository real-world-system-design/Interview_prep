#include<iostream>
using namespace std;

/*
Time Complexity

Monototonic search space 
Each time we are deviding the array into half.

N   --- steps

N/2 --- 1 = N/2^1

N/4 --- 2 = N/2^2

N/8 --- 3 = N/2^3

1 	--- K = N/2^k 

N/2^k = 1

N = 2^k

log base(2) N = K

log base(2) N = K = {logN} -- ANS

-------------------------------
* using mathemetical induction :
-------------------------------

k = constant work to find out the mid 
T(N/2) = Time needed to solve the similar problem of size N/2

T(N) = K + T(N/2)

T(N/2) = K + T(N/4)

T(N/4) = K + T(N/8)
.....
.....
.....
.....
T(1)   = K + 0

----------------------

substitution method

if we add all the terms some are getting cancelled
and we left with

	   logN
T(N) = sum = K logN = O(logN)

*/

int main() {


	return 0;
}