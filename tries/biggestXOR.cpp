#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Given an array find out the maximum xor you can form by picking two from the array

input[] = {3, 10, 5, 8, 2, 25};

output = 28

Explation: 5 XOR 25 = 28
*/
int bigXOR(vector<int> &num) {
	int curr_ans = 0;
	int max_ans = 0;
	for(int i =0; i< num.size(); i++) {
		for(int j = i; j < num.size(); j++) {
			curr_ans = num[i] ^ num[j];
			if(curr_ans > max_ans) {
				max_ans = curr_ans;
			}
		}
	}
	return max_ans;
}


	//if the right pointer is not null we have 1 in the right
	//if the left pointer is not null that means in the left we have 0
class Node {
public:
	Node* left;
	Node* right;
};

class Trie {
	Node* root;
public:
	Trie() {
	root = new Node();
	}

	void insert(int n) {
		//bits of that number in the trie
		Node* temp = root;
		for(int i = 31;i >= 0; i--) {
			int bit = (n>>i)&1;
			if(bit==0){
				if(temp->left==NULL) {
					temp->left = new Node();
				}
				temp = temp -> left;
			}else{
				if(temp->right == NULL) {
					temp -> right = new Node();
				}
				temp = temp->right;
			}
		}
	}

	int max_xor_helper(int val) {
		int curr_ans = 0;
		Node* temp = root;

		//if we have a 0 in the cuurnt node we will look for 1 and vice-versa
		//3, 10, 5, 25
		// 			1 1 0 0 1

		for(int j =31; j >= 0; j--) {
			int bit = (val>>j)&1;

			if(bit == 0) {
				//look for an opposite
				if(temp -> right != NULL) {
					temp = temp -> right;
					//1 << j means (2)^j
					curr_ans += (1<<j);
				}else{
					temp = temp -> left;
				}
			}else{
			if(temp -> left != NULL) {
				temp = temp -> left;
				curr_ans += (1<<j);
			}else{
				temp = temp -> right;
			}
		}
		}	
		return curr_ans; 
	}
	
	int max_xor(vector<int> &input, int n) {
		
		int max_xor = 0;
		for(int i =0; i< n; i++) {
			int value = input[i];
			insert(value);
			int curr_xor = max_xor_helper(value);
			max_xor= max(max_xor, curr_xor);
		}
		return max_xor;
	}
};


int main() {

	vector<int> num {3, 10, 5, 8, 2, 25};
	int n = num.size();

	Trie t;

	cout<<t.max_xor(num, n);

	return 0;
}