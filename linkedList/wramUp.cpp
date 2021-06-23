#include<iostream>
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

int length(Node*head) {
	int len = 0;
	while(head != NULL) {
		head = head -> next;
		len ++;
	}
	return len;
}

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

void insertAtTail(Node*&head, int data) {
	if(head == NULL) {
		head = new Node(data);
		return;
	}
	Node* tail = head;
	while(tail -> next != NULL) {
		tail = tail -> next;
	}
	tail -> next = new Node(data);
	return;
}

void insertAtMiddle(Node*&head, int data, int p) {
	if(head == NULL || p == 0) {
		insertAtHead(head, data);
	}else if(p > length(head)) {
		insertAtTail(head, data);
	}else{
		// Insert in the middle
		// Take p-1 jumps
		int jump = 1;
		Node* temp = head;
		while(jump <= p-1) {
			temp = temp -> next;
			jump++;
		}
		Node* n = new Node(data);
		n -> next = temp -> next;
		temp -> next = n;
	}
}
 
bool searchRec(Node* head, int key) {
	if(head == NULL) {
		return false;
	}
	if(head->data == key) {
		return true;
	}else{
	    return searchRec(head->next, key);
	}	
}

bool searchIteratively(Node* head, int key) {
	while(head != NULL) {
		if(head -> data == key) {
			return true;
		}
		head = head -> next;
	}
	return false;
}

void deleteAtHead(Node*&head) {
	if(head == NULL) {
		return;
	}
	Node* temp = head;
	head = head -> next;
	delete temp;
	return;
}

void deleteAtTail(Node*&head) {
	if(head == NULL) {
		deleteAtHead(head);
	}
	Node* temp = head;
	Node* prev = NULL;
	while(temp ->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	delete temp;
	prev -> next = NULL;
	return;  
}	

void deleteAtMiddle(Node*head, int pos) {
	if(head == NULL || pos == 0) {
		deleteAtHead(head);
	}
	if(pos > length(head)) {
		deleteAtTail(head);
	}
	int jump = 1;
	Node* temp = head;
	while(jump < pos -1) {
		temp = temp -> next;
		jump ++;
	}
	Node* q = temp -> next;
	temp -> next = q -> next;
	q -> next = NULL;
	delete q;
	return; 
}

Node* midpoint(Node* head) {
	if(head == NULL) {
		return head;
	}

	Node* slow = head;
	Node* fast = head -> next;
	while(fast != NULL && fast -> next != NULL) {
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}

void reverserList(Node*&head) {
	//we need three pointers
	Node* curr = head;
	Node* prev = NULL;
	Node* n;

	while(curr != NULL) {
		// store the next node
		n = curr -> next;
		//assign the value of current to prev
		curr -> next = prev;
		//update the value of current an prev
		prev = curr;
		curr = n;
	}
	head = prev;
}

void printLL(Node * head) {
	while(head != NULL) {
		cout<< head -> data<<"-->";
		head = head -> next;
	}
	cout<<endl;
} 

int main() {
	Node* head = NULL;
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtTail(head, 3);
	insertAtMiddle(head, 4, 3);
	insertAtTail(head, 5);
	printLL(head);	
	Node* m = midpoint(head);
	cout<<"midpoint is "<<m->data<<endl;
	cout<<"Length is "<<length(head)<<endl;
	return 0;
}