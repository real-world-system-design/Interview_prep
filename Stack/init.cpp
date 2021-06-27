#include<iostream>
#include<stack>
using namespace std;

bool balancedParathesis(string input) {
	stack<char> s;
	for(auto ch: input) {
		switch(ch) {
			case '(':
			case '{':
			case '[': s.push(ch); break;
			case ')': if(s.empty() || s.top() != '(') return false; else s.pop();break;
			case '}': if(s.empty() || s.top() != '}') return false; else s.pop();break;
			case ']': if(s.empty() || s.top() != ']') return false; else s.pop();break;
			default: ;
		}
	}
	return s.empty();
}

int main() {
	string s = "(()())";
	if(balancedParathesis(s)) {
		cout<< "matched"<<endl;
	}else{
		cout<< "dont match"<<endl;
	}
	return 0;
}