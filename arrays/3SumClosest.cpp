#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int tar) {
	if(nums.size() < 3) return 0;
	int closest = nums[0] + nums[1] + nums[2]; 
	sort(nums.begin(), nums.end());
	for(int first = 0; first < nums.size() - 2; ++first) {
		if(first > 0 and nums[first] == nums[first - 1]) continue;
		int second = first + 1;
		int third = nums.size() - 1;
		while(second < third) {
			int curSum = nums[first] + nums[second] + nums[third];
			if(curSum == tar) return curSum;
			if(abs(tar - curSum) < abs(tar -closest)) {
				closest = curSum;
			}
			if(curSum > tar) {
				--third;
			}else {
				++second;
			}
		}
	}
	return closest;
}

int main() {

	vector<int> v{-1, 2, 1, -4};
	int tar;
	cin>>tar;
	cout<<threeSumClosest(v, tar);

	return 0;
}