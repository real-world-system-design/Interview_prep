#include<iostream>
#include<vector>
using namespace std;

int lower_bound(vector<int> arr, int key) {
	int s = 0;
	int e = arr.size()-1;
	int ans = 0;
	

	while(s <= e) {
	int mid = (s+e)/2;
		if(arr[mid] == key) {
			ans = mid;
			e = mid-1;
		}else if(arr[mid] < key) {
			s = mid + 1;
		}else {
			e = mid - 1;
		}
	}
	return ans;
}

int upper_bound(vector<int> arr, int key) {
	int s = 0;
	int e = arr.size()-1;
	int ans = 0;

	while(s <= e) {
		int mid = (s+e)/2;
		if(arr[mid] == key) {
			ans = mid;
			s = mid + 1;
		}else if(arr[mid] > key) {
			e = mid - 1;
		}else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {

	vector<int> arr = {1, 2, 2, 2, 3, 4, 5};

	cout<<lower_bound(arr, 2);
	cout<<endl;
	cout<<upper_bound(arr, 2);
	return 0;
}