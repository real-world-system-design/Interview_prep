#include<iostream>
#include<list>
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
};

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);
	g.adjList();
	return 0;
}