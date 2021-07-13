#include<iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
	char data;
	unordered_map<char, Node*> children;
	bool terminal;

	Node(int d) {
		data = d;
		terminal = false;
	}
};

class SuffixTrie {

	Node* root;
public:

	SuffixTrie() {
		root = new Node('\0');
	}

	//insert
	void insert_helper(string w) {
		Node* temp = root;
		//traversing the word letter by letter
		for(int i = 0;i < w[i] != '\0'; i++) {
			char ch = w[i];
			if(temp -> children.count(ch)){
				temp = temp -> children[ch];
			}else{
				Node* n = new Node(ch);
				temp -> children[ch] = n;
				temp = n;
			}
		}
		temp -> terminal = true;
	}

	//search
	bool find(string w) {
		Node* temp = root;
		for(int i =0; i< w[i] != '\0'; i++) {
			char ch = w[i];

			if(temp->children.count(ch)==0) {
				return false;
			}else {
				temp = temp -> children[ch];
			}
		}
		return temp -> terminal;
	}

	void insert(string word){
		for(int i =0; i< word[i] != '\0'; i++) {
			insert_helper(word.substr(i));
		}
	}
};

int main() {

	string input = "hello";
	string suffixes[] = {"lo", "ell", "hello"};

	SuffixTrie t;

	t.insert(input);

	for(auto sf: suffixes) {
		if(t.find(sf)) {
			cout<<"yes";
		}else{
			cout<<"No";
		}
	}

	return 0;
}