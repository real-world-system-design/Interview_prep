#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Time Complexity
Base case -- O(N)
worst case -- O(N^2)
*/

void bubbleSort(vector<int> &arr, int n) {
	int i,j;
	bool swapped;
	for(i = 0; i < n-1; i++) {
		swapped = false;
		for(j =0; j < n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		//if no two elements were swapped by inner loop then break
		if(swapped == false)
			break;
	}
}

int main() {

	vector<int> arr = {5, 4, 3, 2, 1};
	int n = arr.size();

	bubbleSort(arr, n);
}