#include <iostream>
using namespace std;

int waterTrapped(int *arr, int n) {
	int result = 0;
	for(int i=0;i<n-1;i++) {
		//to store the max water
		//find max element on it's left
		int left = arr[i];
		for(int l=0;l<i;l++) {
			left = max(left, arr[l]);
		}
		//find the max element on it's right
		int right = arr[i];
		for(int r=0;r<n;r++) {
			right = max(right, arr[r]);
		}
		result = min(left, right) - arr[i]; 
	}
	return result;
}

int main() {
	int arr[] = {0, 2, 1, 3, 0, 1, 2, 2, 1};
	int n = sizeof(arr)/sizeof(int);
	cout<<waterTrapped(arr, n);
	return 0;
}