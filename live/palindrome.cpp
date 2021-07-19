#include <iostream>
using namespace std;

bool palin(int n) {
	//121 -- yes
	int temp = n;
	int revNum = 0;

	while(temp > 0) {
		int last = temp % 10;
		revNum = revNum * 10 + last;
		temp /= 10;
	} 
	if(revNum == n) {
		return true;
	}
	return false;
}

int main () {
	int n = 122;
	if(palin(n)) {
		cout<<"yes";
	}else{
		cout<<"No";
	}

	return 0;
}