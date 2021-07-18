#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

//to store the data (Linked List)
class Node{
public:
	string key;
	int value;
	Node(string key, int value) {
		this -> key = key;
		this -> value = value;
	}
};

//LRU cache implementation
class LRUCache {
	//to define the max num of elements
	int maxsize;
	list<Node> l;

	//this is the address of a perticular node that is 
	//there inside a list
	unordered_map<string, list<Node>::iterator > m;

	LRUCache(int maxsize) {
		this -> maxsize = maxsize > 1 ? maxsize : 1;
	}

	void insert(string key, int value) {
		//present or not present
		if(m.count(key)!=0) {
			//replace the old value
			auto it = m[key];
			it -> value = value;
		}else {
			//check if the cache is present or not
			//if it is full then we have to remove the last item from the list
			//least recently used item from cache
			if(l.size()==maxsize) {
				Node last = l.back();
				m.erase(last.key); //removes from the hashmap 
				l.pop_back(); //removes from the linked list
			}

			//whatever new node you have inserted in the hashmap you need to insert
			//new followed by the address (address of the node in the begining of the list)
			Node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
			 	
		}
	}

	int getValue(int key) {

	}

	string mostRecentKey() {

	}

};

int main() {

	return 0;
}