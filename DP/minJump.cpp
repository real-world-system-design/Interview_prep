#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int minJumps(vector<int> arr, int n, vector<int> dp, int i=0) {
	//base case
	if(i == n-1) {
		return 0;
	}
	if(i >= n) {
		return INT_MAX;
	}

	//assume
	int steps = INT_MAX;
	int max_jump = arr[i];
	for(int jump=1;jump <= max_jump; jump++) {
		int next_cell = i + jump;
		//can calculate how many steps are needed from the subprob
		int sub_problem = minJumps(arr, n, dp, next_cell);
		if(sub_problem != INT_MAX) {
			steps = min(steps, sub_problem +1);
		}
	}
	return dp[i] = steps;
}

int main() {

	vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
	int n = arr.size();

	//create an array for db
	vector<int> dp(n, 0);
	cout<<minJumps(arr, n, dp, 0)<<endl;


	return 0;
}