#include <iostream>
using namespace std;

//find out a square root of a number upto a given precission
//find out a number which is as big as possible and less than the given number


float root(int num, int p) {
	int s = 0;
	int e = num;
	float ans = 0;

	//we can break this code into two parts 
	//1. Binary search --- integer part
	while(s <= e) {
		int mid = (s+e)/2;
		if(mid*mid == num) {
			return mid;
		}else if(mid*mid < num) {
			ans = mid;
			s = mid + 1;
		}else {
			e = mid - 1;
		}
	}
	//2. Linear search for each place --- floating part
	float inc = 0.1;
	for(int places = 1; places <= p; places++) {
		while(ans*ans <= num) {
			ans += inc;
		}
		//take one step back
		//this loop will break when ans is greater than N
		//but we have to go till the num of precessions 
		//given by the user
		ans = ans - inc;
		inc = inc/10.0;
	}
	return ans;
}	

int main() {

	int n,p;
	cin>>n>>p;

	root(n, p);

	return 0;
}