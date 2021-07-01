#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int water(int *arr, int n) {
	int result = 0;
	for(int i = 0;i < n; i++) {
		int left = arr[i];
		for(int left_max= 0;left_max< i;left_max++){
			left = max(left, arr[left_max]);
		}
		int right = arr[i];
		for(int right_max = right; right_max < n; right_max++) {
			right = max(right, arr[right_max]);
		}
		result = min(left, right) - arr[i];
	}
	return result;
}

int main() {
	vector<int> v{1,8,6,2,5,4,8,3,7};
	// int arr[] = {0, 2, 1, 3, 0, 1, 2, 2, 1};
	// int n = sizeof(arr)/sizeof(int);
	cout<<!v.empty();
	return 0;
}