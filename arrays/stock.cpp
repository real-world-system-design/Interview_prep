#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int buysell(vector<int> &prices) {
	int buyVal = 0;
	int sellVal = 0;
	for(auto it: prices) {
		buyVal = min(0, prices[it]);
	}
	// int idx = prices.find(buyVal);
	for(auto i){
		max(0, prices[it]);
	}
	return sellVal - buyVal;
}

int main() {
	// vector<int> v(1, 5, 7, 2, 3);
	// cout<<buyVal(v);
	return 0;
}