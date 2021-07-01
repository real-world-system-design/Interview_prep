#include<iostream>
#include<list>
#include <queue>
using namespace std;

class Graph {
	int v;
	//l is a list of pointers where each element in the array is a list
	list<int> *l;
public:
	Graph(int v) {
		this -> v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void adjList() {
		//iterate over all the vertices 
		//for every linked list we keep a variable called nbr
		//iterate over ith linked list
		for(int i=0; i< v;i++) {
			cout<<"vertex "<<i<<" -->";
			for(auto nbr: l[i]) {
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int src) {
		//data structures
		//1. queue
		//2. visited array
		queue<int> q;
		bool* visited = new bool[v]{0};

		q.push(src);
		visited[src] = true;

		while(!q.empty()) {
			int f = q.front();
			q.pop();
			cout<<f<<" ";
			//visit it's neighbour elements
			for(int nbr: l[f]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	// g.adjList();
	g.bfs(0);
	return 0;
}