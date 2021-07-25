#include <iostream>
using namespace std;

/*
1. Make adjacency list

2. If there is no odd length cycle then the graph is bipartite .

Q> is there a better a way to detect odd length cycle
ANS> yes we can use graph coloring problem to find out the odd length cycle

*/

bool isBipartite(vector<int> &adj, int N, int node, vector<int> &color) {
	queue<int> q;
	q.push(node);
	color[node] = 1;
	//process current graph component using BFS
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(int ele: adj[curr]) {
			if(color[ele] == color[curr]) { //odd-cycle
				return false;
			}
			if(color[ele] == -1) { //unvisited node
				color[ele] = 1-color[curr];
				q.push(ele);
			}
		}
	}
	return true;
}

bool possibleBipartition(int N, vector<vector<int> > &dislikes) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int> > adj(N+1);
	for(int i =0; i < dislikes.size();i++) {
		adj[dislikes[i][0]].push_back(dislikes[i][1]);
		adj[dislikes[i][1]].push_back(dislikes[i][0]);
	}
	vector<int> color(N-1, -1);
	for(int i=1; i<=N; ++i) {
		if(color[i]==-1) 
			if(!isBipartite(adj, N, i, color))
				return false;
	}
	return true;
}


int main() {


	return 0;
}