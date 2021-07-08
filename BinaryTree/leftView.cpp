#include<iostream>
#include<vector>
using namespace std;

class Node {
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
	int d;
	cin>>d;

	if(d == -1) {
		return NULL;
	}

	Node* root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void print(Node* root) {
	if(root == NULL) {
		return ;
	}
	cout<<root -> data<< " ";
	print(root->left);
	print(root->right);
	return;
}

void rightViewUtil(Node* root, int level, int *max_level) {
	if(root == NULL) return;

	if(*max_level < level) {
		cout<<root->data<<" ";
		*max_level = level; 
	}

	//rec call right subtree first and then left
	rightViewUtil(root->right, level+1, max_level);
	rightViewUtil(root->left, level+1, max_level);
}

void leftView(Node* root) {
	int max_level = 0;
	rightViewUtil(root, 1, &max_level);
}

int main() {
	Node* root = buildTree();

	print(root);

	cout<<endl;

	leftView(root);

	return 0;
}