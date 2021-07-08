#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <list>
using namespace std;

class Graph {
	int v;
	//l is a list of pointer where each element in the array is a list
	list<int> *l;
public:
	Graph(int v) {
		this -> v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y, int wt, bool undir = true) {
		l[x].push_back({wt, y});
		if(undir) {
			l[y].push_back({wt, x});
		}
	}

	void adjList() {
		//iterate over all the vertices
		//for every list we keep a variable called nbr
		//iterate over ith linked list
		for(int i =0; i< v; i++) {
				cout<< "vertex "<<i <<"-->";
			for(auto nbr : l[i]) {
				cout<<nbr<<",";
			}
		cout<<endl;
		}
	}

	//weighted graph single source sortest path
	int dijkstra(int src, int dest) {
		//data structures required
		
		//we have v nodes and all initialized with infinity initially
		vector<int> dist (v, INT_MAX);

		//set will store a pair of current node and it's distance
		set<pair<int, int> > s;

		//Node form itself is zero
		dist[src] = 0;

		//initialize the set
		s.insert({0, src});

		while(!s.empty()) {
			auto it = s.begin();
			int node = it -> second;
			int distTillNow = it -> first;
			//pop operation
			s.erase(it);
			//iterate over the nbr of node
			for(auto nbrPair: l[node]) {
				auto nbr = nbrPair.second;
				auto currEdge = nbrPair.first;
				if(distTillNow + currEdge < dist[nbr]) {
					dist[nbr] = distTillNow + currEdge;
					//if a pair exists remove
					auto f = s.find({dist[nbr], nbr});
					if(!s.end()) {
						s.erase(f);
					}
					//insert the updated value with the new dist
					s.insert({dist[nbr], nbr});
				}
			}
		}

		for(int i =0; i< v; i++) {
			cout<<"Node "<<i<< " dist "<<dist[i]<<endl;
		}

		return dist[dest];

	}
};

int main() {
	Graph g(4);
	// g.addEdge(0, 1);
	// g.addEdge(0, 3);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(3, 4);
	// g.addEdge(4, 5);
	g.adjList();
	return 0;
}