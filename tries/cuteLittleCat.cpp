#include <iostream>
#include<unordered_map>
using namespace std;

//called as a prefix tree because they store common prefixes in the same branch
class Node{
public:
	char data;
	bool terminal;
	unordered_map<char, Node*> children;

	Node(char d) {
		data = d;
		terminal = false;
	}
};

class Trie {
public:
	Node* root;
	int cnt;

public:
	Trie() {
		root = new Node('\0');
		cnt = 0;
	}
	void insert(char *w) {
		Node* temp = root;
		//At every step we have to check if the current charecter is present or not
		//basically we are traversing word letter by letter
		for(int i =0; w[i] != '\0';i++) {
			//current charecter is exists or not
			char ch = w[i];
			if(temp -> children.count(ch)) {
				//if the value is present then we are going to return the address of that node
				temp = temp->children[ch];
			}else{
				//if the node is not present then we are going to create a temporary node
				//and then we have to store the address of the new node in the hash map
				//corespondes to the key given by the user
				Node* n = new Node(ch);
				temp -> children[ch] = n;
				temp = n;
			}
		}//we have reach at the leaf node
		temp->terminal=true;
	}
};

//starting from the index i till the end and if a word is present we're gonna 
//store them inside a map
void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m) {

	//start from the given index if a word can be found or not
	Node* temp = t.root;
	for(int j = i; j < document.length(); j++) {
		char ch = document[j];
		if(temp -> children.count(ch)==0) {
			return;
		}
		temp = temp -> children[ch]; 
	} 
}

void docSearch(string document, string [] words) {
	//1. insert these words into a trie object
	Trie t;
	for(auto w: words) {
		t.insert(words);
	}

	//2. Searching (helper fn)	
	//map the maps we have found so far
	unordered_map<string, bool> m;
	//create all the suffixes starting from the index i till the end
	for(int i=0; i<document.length();i++) {
		searchHelper(t, document, i, m)
	}
}

int main() {

//we have to find a give word and it's substrings are present or not in a string

	string doc = "kubernetes is a container orchastrain tool which helps 
	in load balancing, auto scaling, automated roll backs and roll outs,
	disaster recovery";

	string word[] = ["kubernetes", "docker", "container", "load"];

	return 0;
}