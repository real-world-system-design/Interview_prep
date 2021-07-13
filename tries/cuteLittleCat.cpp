#include <iostream>
#include<unordered_map>
#include<cstring>
#include <vector>
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

	Trie() {
		root = new Node('\0');
	}
	void insert(string word) {
		Node* temp = root;

		for(char ch: word) {

			if(temp -> children.count(ch) == 0) {
				Node* n = new Node(ch);
				temp -> children[ch] = n;
			}
			temp = temp->children[ch];							
			
		}
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
		if(temp->terminal) {
			//history part
			string out = document.substr(i, j-i+1);
			m[out] = true;
		} 
	} 
	return;
}

void docSearch(string document, vector<string> words) {
	//1. insert these words into a trie object
	Trie t;
	for(string w: words) {
		t.insert(w);
	}

	//2. Searching (helper fn)	
	//map the maps we have found so far
	unordered_map<string, bool> m;
	//create all the suffixes starting from the index i till the end
	for(int i=0; i<document.length();i++) {
		searchHelper(t, document, i, m);
	}

	//3. Check which words are marked as true inside Hashmap
	for(string w: words) {
		if(m[w]) {
			cout<<w<< " True"<<endl;
		}else{
			cout<<w<<" False"<<endl;
		}
	}
	return;
}

int main() {

//we have to find a give word and it's substrings are present or not in a string

	string doc = "kubernetes is a container orchastrain tool which helps";

	vector<string> words{"kubernetes", "docker", "container", "load"};

	docSearch(doc, words);

	return 0;
}