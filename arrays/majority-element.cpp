#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//using unorder map
int majority(vector<int>& nums) {
	unordered_map<int, int> counter;

	for(int num: nums) {
		if(++counter[num] > nums.size()/2) {
			return num;
		}
	}
	return 0;
}

//using moore voting algo
int majorityMV(vector<int> nums) {
	int counter = 0, majority;
	for(int num: nums) {
		if(!counter) {
			majority = num;
		}
		counter += num == majority ? 1: -1;
	}
	return majority;
} 

int main() {
	vector<int> nums{1, 2, 2, 2, 3, 2};
	cout<<majorityMV(nums);
	return 0;
}