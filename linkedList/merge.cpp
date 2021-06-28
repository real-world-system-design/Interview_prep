#include<iostream>
// #include<list>
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
	Node* n = new Node(data);
	n -> next = head;
	head = n;
}

void printLL(Node* head) {
	while(head != NULL) {
		cout << head->data<<"-->";
		head = head -> next;
	}
	cout<<"NULL";
}

Node* mergeTwoLists(Node*&l1, Node*&l2) {
	Node dummy(0);
	Node *tail = &dummy;
	while(l1 != NULL and l2 != NULL) {
		Node *& node = l1 -> data < l2 -> data ? l1 : l2;
		tail = tail -> next = node;
		node = node -> next;
	}
	tail -> next = l1 ? l1 : l2;
	return dummy.next;
} 

int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	insertAtHead(head1, 5);
	insertAtHead(head1, 1);
	printLL(head1);
	cout<<endl;
	insertAtHead(head2, 6);
	insertAtHead(head2, 4);
	printLL(head2);
	mergeTwoLists(head1, head2);
	return 0;
}