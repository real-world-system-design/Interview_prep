#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Graph {
	int v;
	list<int>* l;

	Graph(int v) {
		this -> v = v;
		l = new list<int>[v];
	}
	void addEdge(int u, int v, int wt, bool undir = true){
		l[u].push_back({wt, v});
		if(bidr){
			l[v].push_back({wt, u});
		}
	}
	int dijkstra(int src, int dest) {
		//data structures needed
		// 1. set will store the current node and it's distance
		// 2. visited array
		vector<int> dist(v, INT_MAX);
		set<pair<int , int> >s;

		dist[src] = 0;
		//initialize the set
		s.insert({0, src});
		

	}
}

int main() {


	return 0;
}