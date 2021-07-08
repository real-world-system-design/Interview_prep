#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int d) {
		d = data;
		next = NULL;
	}
};

void insertAtHead(Node*&head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	Node* temp = new Node(data);
	temp -> next = head;
	head = temp;
}

void printLL(Node* head) {
	while(head) {
		cout<<head->data<<"-->";
		head = head -> next;
	}
	cout<<"NULL";
}

int main() {

	Node* head = NULL;
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	printLL(head);
	return 0;
}