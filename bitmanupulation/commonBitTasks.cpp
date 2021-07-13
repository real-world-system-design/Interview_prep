#include <iostream>
using namespace std;

//011
//001
//odd number
bool isOdd(int n) {
	return n&1;
}

//>> devide by 2
//<< mul by 2
int getBit(int n, int i) {
	//Find ith bit (Right)
	int mask = (1<<i);
	int bit = (n&mask) > 0 ? 1 : 0;
	return bit;
}

//010
//110
int setBit(int n, int i) {
	int mask = (1 << i);
	int ans = n | mask;
	return ans;
}

void clearBit(int &n, int i) {
	int mask = ~(1<<i);
	cout<<mask<<endl;
	n = n&mask;
	cout<<n<<endl;
}

void updateBit(int &n, int i, int v) {
	int mask = ~(1<<i);
	int cleared_no = n&mask;
	n = cleared_no | (v<<i);
}

int main() {
	int n;
	cin>>n;
	clearBit(n, 2);
	return 0;
}