#include<iostream>
#include <vector>
#include<unordered_set>
using namespace std;

class Node {
public:	
	int data;
	Node* next;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtHead(Node*&head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	//otherwise
	Node* n = new Node(data);
	n -> next = head; 
	head = n;
}

void printLL(Node* head) {
	while(head != NULL) {
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"NULL";
}

Node* removeDups(Node*&head) {
	//hash to store seen values
	unordered_set<int> seen;

	//pick elements one by one
	Node* curr = head;
	Node* prev = NULL;
	while(curr != NULL){
		//if current value is seen before
		if(seen.find(curr-> data) != seen.end()){
			prev->next = curr->next;
			delete curr;
		}else{
			seen.insert(curr->data);
			prev = curr;
		}
		curr = prev->next;
	}
}

int main() {
	Node* head = NULL;
	insertAtHead(head, 3);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	// cout<<"list before removing duplicates"<<endl;
	// printLL(head);
	// // removeDups(head);
	// cout<<"list after removing duplicates"<<endl;
	// printLL(head);
	
	return 0;
}