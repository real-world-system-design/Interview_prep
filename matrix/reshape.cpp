#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
	int m = mat.size();
	int n = mat[0].size();
	int total = m * n;

	if(r * c != total) return mat;

	vector<vector<int>> ans(r, vector<int>(c));
	for(int i =0; i < total; i++) 

		//i/c --> determines which row
		//i%c --> determines which col

		ans[i/c][i%c] = mat[i/n][i%n];
	return ans;
	
 }

int main() {

	vector<vector<int>> v
	{
		{1, 2},
		{4, 5},
	};

	matrixReshape(v, 1, 4);

	for(int i=0;i< v.size(); i++) {
		for(int j =0; j< v[i].size(); j++) {
			cout<< v[i][j]<< " ";
		}
		cout<<endl;
	}

	return 0;
}