#include<iostream>
#include<unordered_map>
using namespace std;

/*generic tree like data structures
efficient information retrival data structure
searches in optimal time O(key length) but usages extra space.
* Important operations :
- Insert a new word 
- Search for a given word
Q. why it called as prefix tree ?
-  Is stores common prefixes in the same branch
*/

class Node {
public:
	char data;
	unordered_map<char, Node*> m;
	bool terminal;
	Node(char d) {
		data = d;
		terminal = false;
	}
};

class Trie {
/*point to the null at the beginning 
it will not have any children at the beginning 
data inside this node is null
you will create this node inside a constructor
when a trie object is created this root pointer points to empty node
*/
Node* root;
Trie(){
	root = new Node('\0');
}

void insert(string word) {
	Node* tmp = root;
	for(char ch: word) {
		if(tmp -> m.count(ch) == 0) {
			Node* n = new Node(ch);
			tmp -> m[ch] = n;
		}//we can go to next char and bring
		tmp = tmp -> m[ch];
	}
	tmp -> terminal = true;
}

bool search(string word) {
	Node* tmp = root;
	for(char ch: word) {
		if(tmp -> m.count(ch) == 0) {
			return false;
		}
		tmp = tmp -> m[ch];
	}
	//if tmp is a terminal node it will return true otherwise false
	return tmp -> terminal;
}		

};

int main() {

	string words [] = {"apple", "ape", "no", "news"};
	Trie t;
	for(auto w:words) {
		t.insert(w);
	}
	int q;
	cin>>q;
	string search_word;
	while(q--) {
		cin>>search_word;
		if(t.search(search_word)) {
			cout<<"exists"<<endl;
		}else{
			cout<<"Not exists"<<endl;
		}
	}
	return 0;
}