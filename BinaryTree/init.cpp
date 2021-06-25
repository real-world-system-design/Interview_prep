#include<iostream>
using namespace std;
	
class Node{
public:	
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* buildTree() {
	int data;
	cin>>data;

	if(data == -1) {
		return NULL;
	}
	Node *n = new Node(data);
	n -> left = buildTree();
	n -> right = buildTree();
	return n;
}

void print(Node* root) {
	if(root == NULL) {
		return;
	}
	//print the root first followed by the subtree
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int main() {
	Node* root = buildTree();
	print(root);
	return 0;
}