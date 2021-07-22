#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void min_pair(vector<int> a1, vector<int> a2) {

	//sort the array
	sort(a2.begin(), a2.end());

	int p1,p2;
	int diff = INT_MAX;

	//iterate over 1 array and look for closest elements in the second array
	for(int x: a1) {
		//subtract the base address you get an index
		auto lb = lower_bound(a2.beginn(), a2.end(), x) - a2.begin();
	
		if(lb >= 1 and x - a2[lb-1] < diff) {
			diff = x - a2[lb-1];
			p1 = x;
			p2 = a2[lb - 1];
		}
		//greater / right
		if(lb != a2.size() and a2[lb] - x < diff) {
			diff = a2[lb] - x;
			p1 = x;
			p2 = a2[lb];
		}
	}
	cout<<"Min pair"<<p1<<"and"<<p2<<endl;
}


int main() {

	vector<int> a1 = {-1, 5, 10, 20, 3};
	vector<int> a2 = {26, 134, 135, 15, 17};
	min_pair(a1, a2);


	return 0;
}
