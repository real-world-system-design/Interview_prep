#include<iostream>
using namespace std;

// num = 5 = 101
//           abc

//time -- O(n*2^n)

//print the subsequence of a string
void filter_bits(char arr[], int num) {
	//find out all the bits while num > 0
	int j =0;

	//for every number we are iteraitng the 
	//number of bits we have
	// O(N)
	while(num>0) {
		int last_bit = (num&1);
		if(last_bit) {
			cout<<arr[j];
		}
		j++;
		num = (num>>1);
	}
	cout<<endl;
}


int main() {
	char arr[] = "abc";

	int n = 3;

	//O(2^n)
	for(int i=0;i<(1<<n);i++) {
		filter_bits(arr, i); //N
	}

	return 0;
}