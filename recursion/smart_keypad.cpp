#include <iostream>
#include<cstring>
using namespace std;


//by default null terminated but if you are using a charecter array yoou have to explicitily 
//terminate with NULL 
string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV","WXYZ"};

void printKeyPadOut(string input, string output, int i =0) {
	if(input[i] == '\0') {
		cout<<output<<endl;
		return;
	}
	//rec case
	int current_digit = input[i] - '0';
	//special case if your input does not contain 0 or 1 you can skip it
	//ask for clarification to the interiewer
	if(current_digit == 0 or current_digit == 1) {
		printKeyPadOut(input, output, i+1);
	}
	//keypad
	for(int k=0; k< keypad[current_digit].size(); k++) {
		printKeyPadOut(input, output + keypad[current_digit][k], i+1);
	}
	return;
}

int main() {


	return 0;
}