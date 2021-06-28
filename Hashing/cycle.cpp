#include<iostream>
#include<string>
#include<unordered_map>
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


bool containsCycle(Node* head) {
	unordered_map<Node*, bool> m;

	Node* tmp = head;
	while(tmp != NULL) {
		if(m.count(tmp) != 0) {
			return true;
			break;
		}
		//insert in the hashtable
		m[tmp] = true;
		tmp = tmp -> next;
	}
	return false;
}

int main() {
	Node* head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 3);
	insertAtHead(head, 3);

	//comment this in this causes the cycle 
	Node* temp = head -> next -> next -> next -> next ;
	temp -> next = head -> next-> next; 

	if(containsCycle(temp)) {
		cout<<"yea";
	}else{
		cout<<"no";
	}
	return 0;
}