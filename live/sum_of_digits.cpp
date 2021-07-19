#include <iostream>
using namespace std;

int sum(int n) {
	//123 -- 1 + 2 + 3 = 6
	int temp = n;
	int sum = 0;

	while(temp > 0) {
		int last = temp % 10;
		temp /= 10;
		sum += last;
	}
	return sum;
}

int main() {

	cout<<sum(123);

	return 0;
}