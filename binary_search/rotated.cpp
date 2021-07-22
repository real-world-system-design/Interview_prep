#include <iostream>
#include <vector>
using namespace std;

int rotated(vector<int> &arr, int key) {
	int s = 0;
	int e = arr.size()-1;
	int mid;

	while(s <= e) {
		mid = (s+e)/2;
		if(key == arr[mid]) {
			return mid;
		}	

		//2 cases
		if(arr[s] <= arr[mid]) {
			//left
			if(key >= arr[s] and key <= arr[mid]) {
				e  = mid - 1;
			}else {
				s = mid + 1;
			}
		}
		else  {
			//right 
			if(key >= arr[mid] and key <= arr[e]) {
				s = mid  + 1;
			}else {
				e  = mid - 1;
			}
		}
	}
	return -1;
}

int main() {
	vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
	rotated(arr, 6);
	return 0;
}