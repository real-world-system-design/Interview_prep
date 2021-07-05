#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this -> data = data;
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

ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
}

Node* swpaLLPairs(Node*&head) {
	if(head == NULL) {
		return head;
	}
	if(head -> next == NULL) {
		return head;
	}
	Node* next = head->next;
	head->next = swpaLLPairs(next->head);
	next->next = head;
	return next;	
} 

void printLL(Node* head) {
	while(head != NULL) {
		cout<<head->data<<"-->";
		head = head -> next;
	}
	cout<<"NULL";
}

int main() {

	Node* head = NULL;
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	printLL(head);
	return 0;
}