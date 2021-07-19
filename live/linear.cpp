#include<iostream>
#include<vector>
using namespace std;

int linear(vector<int> &num, int key) {
	
	if(key > num.size() -1) {
		return 0;
	}

	for(int i =0; i< num.size(); i++) {
		if(num[i] == key) {
			return num[i];
		}
	}
}

int binary(int *arr, int n, int key) {
	int i = 0;
	int j = n-1;
	int mid = i+j/2;

	while(i <= j) {
		if(arr[mid] == key) {
			return mid;
		}else if(arr[mid] > key){
			j = mid - 1;
		}
		else {
			i = mid + 1;
		}
	}
	return 0;
}

int main() {

	// vector<int> num = {1, 2, 3, 4, 5, 6};
	int arr[5] = {1, 2, 3, 4, 5};
	cout<<binary(arr, 5, 2);

	return 0;
}