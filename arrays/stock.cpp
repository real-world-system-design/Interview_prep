#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int buysell(vector<int> &prices) {
	int currSoFar = 0;
	int maxSoFar = 0;

	for(int i =1; i != prices.size(); i++) {
		currSoFar = max(0, currSoFar += prices[i] - prices[i-1]);
		maxSoFar = max(currSoFar, maxSoFar);
	}
	return maxSoFar;
}

int buysell_II(vector<int> &prices) {
	int ans = 0;

	for(int i =1; i < prices.size(); i++) {
		ans += max(0, prices[i] - prices[i-1]);
	}
	return ans;
}

int main() {
	vector<int> v{7,1,5,3,6,4};
	cout<<buysell_II(v);
	return 0;
}