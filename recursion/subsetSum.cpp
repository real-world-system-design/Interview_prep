#include<iostream>
#include<vector>
using namespace std;

int countSubsets(vector<int> &arr, int n, int i, int sum) {
	//i reaches at the last index
	if(i == n) {
		//we dont need any elements from an empty array
		if(sum == 0) {
			return 1;
		}
		return 0;
	}
	//rec case
	//1. If we include the current element
	int a = countSubsets(arr, n, i+1, sum-arr[i]);
	int b = countSubsets(arr, n, i+1, sum);
	return a+b;
}

int main() {
	vector<int> arr{1, 2, 3, 4, 5};
	int target = 6;
	cout<<countSubsets(arr, arr.size(), 0, target);
	return 0;
}