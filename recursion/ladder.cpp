#include<iostream>
using namespace std;

int ladder(int n) {
	if(n < 0) {
		return 0;
	}
	if(n == 0) {
		return 1;
	}
	//rec case
	return ladder(n-1) + ladder(n-2) + ladder(n-3);
}

int main() {
	int n;
	cin>>n;
	cout<<ladder(n);
	return 0;
}