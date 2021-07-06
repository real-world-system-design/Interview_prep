#include <iostream>
using namespace std;

void convertBinary(unsigned int num) {
	if(num / 2 != 0) {
		convertBinary(num/2);
	}
	cout<<num%2;
}

int main() {
	convertBinary(3);
	return 0;
}