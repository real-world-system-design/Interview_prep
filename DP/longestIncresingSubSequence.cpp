#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> arr) {

	int n = arr.size();
	vector<int >dp(n, 1);

	int len = 1;

	for(int i=1; i< n; i++) {
		//have a less index than i
		for(int j = 0; j< i;j++) {
			//then we check can we attach the ith element at the end of the sequence 
			//which ends at jth element
			if(arr[i] > arr[j]) {
				//because dp[j] denotes the length of the sequence 
				//where the last element is arr[j]
				//and the 1 is added because we are attaching the 
				//arr[i] to ending of the arr[j]
				dp[i] = max(dp[i], 1+dp[j]);
				len = max(len, dp[i]);
			}
		}
	}
	return len;

}

int main() {

	vector<int >arr{50, 4, 10, 8, 30};
	cout<<lis(arr)<<endl;
	return 0;
}