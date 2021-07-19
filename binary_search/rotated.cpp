#include <iostream>
#include <vector>
using namespace std;

int rotated(vector<int> &arr, int key) {
	int s = 0;
	int e = arr.size()-1;

	while(s <= e) {
		int mid = (s+e)/2;
		while(arr[s] <= arr[mid]) {
			if(arr[s] <= key <= arr[mid]) {
				e = mid -1;
			}else{
				s = mid + 1;
			}
		}
		while(arr[mid] <= arr[e]) {
			if(arr[s] <= key <= arr[mid]) {
				s = mid + 1;
			}else {
				e = mid - 1;
			}
		}
	}
}

int main() {
	vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
	rotated(arr, 6);
	return 0;
}