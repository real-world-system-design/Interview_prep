#include<iostream>
#include<vector>
using namespace std;

int main() {

	vector<int> num = {1, 2, 3, 4, 5, 6};

	for(auto n: num) {
		cout<<n<<" ";
	}

	return 0;
}