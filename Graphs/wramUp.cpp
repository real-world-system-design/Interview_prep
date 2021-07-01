#include<iostream>
#include<list>
#include <queue>
using namespace std;

class Graph {
	int v;
	//l is a list of pointers where each element of the array is a list.
	list<int> *l;
public:
	Graph(int v) {
		this -> v = v;
		l = new list<int>[v];
	}
	//in case of a bidirectional edge
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void adjList() {
		//Iterate over all the vertices
		//for every linked list we keep a variable called nbr 
		//that iterates over the ith linked list
		for(int i=0;i<v;i++) {
			cout<<"vertex"<<i<<"-->";
			for(int nbr: l[i]) {
				cout<<nbr<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int src, int dest = -1) {
		//data structures
		// 1. queue 2. visited
		queue<int> q;
		bool* visited = new bool[v]{0};

		//update the code to get the sortest path from a given source node
		int *dist = new int[v]{0};
		int *parent = new int[v];

		for(int i=0;i<v;i++) {
			dist[i] = -1;
		}

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			//do some work for every node
			int f = q.front();
			// cout<<f<<endl;
			q.pop();

			//push the neighbours of the node into the list
			for(auto nbr: l[f]) {
				if(!visited[nbr]) {
					q.push(nbr);
					//we have to update the parent and the distance array
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
					visited[nbr] = true;
				}
			}
		}
		//print the sortest distance
		for(int i =0;i<v;i++) {
			cout<<"sotest dist to node "<< i << " is "<<dist[i]<<endl;
		}
		if(dest!=-1) {
			int temp = dest;
			while(temp != src) {
				cout<<temp<<"-- ";
				temp = parent[temp];
			}
			cout<<src<<endl;
		}
	}
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	// g.adjList();
	g.bfs(0);
	return 0;
}