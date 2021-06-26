#include <iostream>
#include<queue>
using namespace std;

class Node {
public:	
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this -> data = data;
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
	Node* n = new Node(data);
	n -> left = buildTree();
	n -> right = buildTree();
	return n;
}

//build a binary tree from level order input
//-1 in input represents NULL
// 1 2 3 4 5 -1 -1 7 -1 -1 -1 -1 -1

Node* levelOrderBuild() {
	int d;
	cin>>d;
	Node* root = new Node(d);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* curr = q.front();
		q.pop();
		int c1, c2;
		cin>>c1>>c2;
		if(c1 != -1) {
			curr -> left = new Node(c1);
			q.push(curr -> left);
		}
		if(c2 != -1) {
			curr -> right = new Node(c2);
			q.push(curr -> right);
		}
	}
	return root;
}

void levelOrder(Node* root) {
	//we need something to store the oputput 
	//queue you guessed it right !
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		if(temp == NULL) {
			cout<<endl;
			q.pop();
			if(!q.empty()) {
				q.push(NULL);
			}
		}else{
			q.pop();
			cout<<temp -> data<< " ";
			if(temp -> left) {
				q.push(temp -> left);
			}
			if(temp -> right) {
				q.push(temp -> right);
			}
		}
	}
	return;
}

int height(Node* root) {
	if(root == NULL) {
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	return 1+ max(h1, h2);
}

int diameter(Node* root) {
	if(root == NULL) {
		return 0;
	}
	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);
	return max(D1, max(D2, D3));
}

int main() {

	Node* root = levelOrderBuild();
	levelOrder(root);
	cout<<diameter(root)<<endl;
	return 0;
}