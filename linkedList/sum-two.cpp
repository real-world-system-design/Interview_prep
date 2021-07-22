#include <iostream>
using namespace std;

class Node{
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
	Node* n = new Node(data);
	n -> next = head;
	head = n;
}

void printLL(Node* head) {
	while(head != NULL) {
		cout<<head -> data<<"-->";
		head = head -> next;
	}
	cout<<"NULL";
}


int main() {

	Node* head1 = NULL;
	Node* head2 = NULL;
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	return 0;
}