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

/*
n unique steps and for every states and for every state we are using a loop
that does O(k) work .
complexity ---- O(n*k)
*/

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

int ladderBU(int n, int k){
	//Iterative approach
	vector<int> dp(n+1, 0);
	dp[0] = 1;

	//we have to sum up the preveius k values
	for(int i =1;i<=n;i++) {
		for(int jump =1;jump<=k;jump++) {
			if(i-jump>=0) {
				dp[i] += dp[i-jump];
			}
		}
	}
	return dp[n];
}

// Bottom up optimized O(n+k)
int buttomUP(int n, int k) {
	vector<int> dp(n+1, 0);

	dp[0] = dp[1] = 1;
	for(int i=0;i<=k;i++) {
		dp[i] = 2*dp[i-1];
	}
	for(int i = k+1; i<=n;i++) {
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}
	return dp[n];
}


int main() {
	int n,k;
	cin>>n>>k;
	int dp[1000] = {0};
	cout<<ladderTD(n,k, dp); 
	return 0;
}