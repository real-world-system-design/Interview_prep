#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int minNoOfCoins(int m, vector<int> denoms) {
	vector<int> dp(m+1, 0);
	dp[0] = 0;

	for(int i=1;i<=m;i++) {
		dp[i] = INT_MAX;

		for(int c: denoms) {
			if(i - c >= 0 and dp[i-c] != INT_MAX) {
				//why +1 because we are using the the coin whose value is c
				dp[i] = min(dp[i], dp[i-c] + 1);
			}
		}
	}
	return dp[m] == INT_MAX? -1 : dp[m];
}

int main() {
	vector<int> denoms = {1, 5, 7, 10};
	cout<<minNoOfCoins(8, denoms)<<endl;
	return 0;
}