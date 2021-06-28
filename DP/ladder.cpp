#include<iostream>
using namespace std;
/*
exponential
n level stev and every level we are making k calls
O(k^n);
*/
int ladder(int n, int k) {
	if(n == 0) {
		return 1;
	}
	if(n < 0) {
		return 0;
	}
	int ans = 0;
	for(int jump = 1;jump <= k;jump++) {
		ans += ladder(n-jump, k);
	}
	return ans;
}

int ladderTD(int n, int k, int *dp) {
	if(n == 0) {
		return 1;
	}
	if(n < 0) {
		return 0;
	}
	//check if state is already computed
	if(dp[n] != 0) {
		return dp[n];
	}
	int ans = 0;
	for(int jump = 1;jump <= k;jump++) {
		ans += ladder(n-jump, k);
	}
	return dp[n] = ans;
}

int main() {
	int n,k;
	cin>>n>>k;
	int dp[1000] = {0};
	cout<<ladderTD(n,k, dp); 
	return 0;
}