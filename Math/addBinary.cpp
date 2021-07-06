#include <iostream>
using namespace std;

void addBinary(unsigned int num) {
	if(num / 2 != 0) {
		convertBinary(num/2);
	}
	cout<<num%2;
}

int main() {



	return 0;
}