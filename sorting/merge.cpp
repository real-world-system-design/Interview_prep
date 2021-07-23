#include <iostream>
using namespace std;

/*

	T(N) = K + T(N/2) + T(N/2) + KN

	T(N) = KN + 2T(N/2)
	2T(N/2) = 2K(N/2) + 4T(N/4)
	4T(N/4) = 4K(N/4) + 8T(N/8) 

	T(N) = I = 1 TILL LOGN KN = KNLOGN = O(NLOGN)
*/

//helper method
void merge(vector<int> &arr, int s, int e) {
	int i = s;
	int mid = (s+e)/2;
	int j = mid + 1;

	vector<int> temp;

	while(i <= mid and j <= e) {
		if(arr[i] < arr[j]) {
			temp.push_back(arr[i]);
			i++;
		}else {
			temp.push_back(arr[j]);
			j++;
		}
	}
	//push the remaining elements to the temp array
	while(i <= mid) {
		temp.push_back(arr[i]);
	}
	while(j <= e) {
		temp.push_back(arr[j]);
	}

	int k =0;
	for(int idx=s; idx<= e;idx++) {
		arr[idx] = temp[k++];
	}
	return;
}

void mergeSort(vector<int> &arr, int s, int e) {
	//base case
	if(s >= e) {
		return;
	}
	//rec case
	int mid = (s+e)/2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid+1, e);
	return merge(arr, s, e);
}

int main() {

	vector<int> arr = {5, 4, 3, 2, 1};
	int n = arr.size()-1;

	return 0;
}