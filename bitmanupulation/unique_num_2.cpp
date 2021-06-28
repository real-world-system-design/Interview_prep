#include<iostream>
#include <vector>
using namespace std;

void printUniqueII(vector<int> nums, int n) {
	//first step
	//we will get 2 ^ 3
	// 1 0
	// 1 1 if we do a xor we get 01 
	// we can separate based upon this set bit
	int result = 0;
	for(int i =0;i<n;i++) {
		result = result ^ nums[i];
	}
	//find out the position of the last setbit
	int pos = 0;
	int temp = result;
	while(temp > 0) {
		if(temp & 1){
			break;
		}
		pos++;
		temp = temp>>1;
	}
	//filter out the numbers which have a set bit at perticular position 'pos'
	//i want those numbers in which the perticular number is set
	int A = 0;
	//use parantesis becoz presidence some times causes problem .
	int mask = (1<<pos);
	for(int i=0;i<n;i++) {
		if((nums[i] & mask) > 0) {
			A = A^nums[i];
		}
	}
	int B = result ^ A;
	cout<< A << endl;
	cout<< B << endl;
}

int main() {
	vector<int> nums = {1, 2, 5, 5, 6, 7, 7, 3, 1, 6};
	int n = nums.size();
	cout<<n <<endl;
	printUniqueII(nums, n);
	return 0;
}