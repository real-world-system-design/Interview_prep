#include <iostream>
using namespace std;

bool canPlaceBirds(int B, int N, vector<int> nests, int sep) {
	//curent placed birds
	int birds = 1;
	//last location
	int location = nests[0];

	for(int i=1; i<=n-1; i++) {
		int curr_loc = nests[i];
		if(curr_loc - location >= sep) {
			birds++;
			location = curr_loc;

			if(birds == B) {
				return true;
			}
		}
	}
	return false;
}

int main() {

	int B = 3;
	vector<int> nests{1, 2, 4, 8, 9};
	//sorting
	sort(nests.begin(), nests.end());
	int N = nests.size();

	//Binary search
	int s = 0;
	//gives us the delta the maximum possible ans we can have
	int e = nests[N-1] - nests[0];

	while(s <= e) {
		int mid = (s+e)/2;

		bool canPlace = canPlaceBirds(B, N, nests, mid);
		if(canPlace) {
			ans = mid;
			s = mid + 1;
		}else {
			e = mid - 1;
		}
	}

	cout<<ans<<endl;

	return 0;
}