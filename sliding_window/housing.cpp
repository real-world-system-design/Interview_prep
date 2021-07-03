#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

void housing(int *arr, int n, int sum) {
	//find the smallest window that contains the require sum

	int i = 0;
	int j = 0;
	int cs = 0;
	int length = 0;
	int minLength = INT_MAX;

	while(j<n) {
		cs += arr[j];
		j++;

		//remove element from the left
		while(cs > sum and i < j) {
			cs = cs - arr[i];
			i++;
		}
		//check if any given point
		if(cs == sum){
			// cout<<i << " - "<< j<<endl;
			length = min(sum, j-1-i);
			if(length < minLength) {
				minLength = length;
			}  
		}
	}
	cout<<minLength<<endl;	
	return;
}


int main() {
	int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
	int n = sizeof(plots)/sizeof(int);
	int k = 8;
	housing(plots, n, k);
	return 0;
}