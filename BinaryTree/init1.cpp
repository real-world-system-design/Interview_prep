#include<iostream>
using namespace std;

class Node{
public: 
	int d;
	Node* left;
	Node* right;

	Node(int d) {
		this -> d = d;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree() {
	int d;
	cin>>d;

	if(d == -1) {
		return NULL;
	}
	Node * root = new Node(d);
	root -> left = buildTree();
	root -> right = buildTree();
	return root;
}

void print(Node* root) {
	if(root == NULL) {
		return;
	}
	//otherwise print the root folowed by the subtrees
	cout<< root -> d << " ";
	print(root -> left);
	print(root -> right); 
}

int main() {
	Node* root = buildTree();
	print(root);
	return 0;
}