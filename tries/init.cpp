#include <iostream>
#include<unordered_map>
using namespace std;

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
	bool find(char *w){
		Node* temp = root;

		//travering the whole array till bottom
		for(int i=0;w[i] != '\0';i++) {
			char ch = w[i];
		//check if the charecter which we are looking for is present in the map or not
		if(temp -> children.count(ch)==0) {
			return false;
		}else{
			//return the address of the next node
			temp = temp->children[ch];
			cout<<i<<endl;
		}
	}
	//return if temp is terminal
	return temp->terminal;
	}
};

int main() {

Trie t;

char words[][10] = {"apple","mango","papaya","grapes","orange"};
char w[10];
cin>>w;

for(int i=0;i<5;i++) {
	t.insert(words[i]);
}

if(t.find(w)) {
	cout<<"present"<<endl;
}else{
	cout<<"absent";
}

	return 0;
}