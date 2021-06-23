#include<iostream>
#include<algorithm>
using namespace std;

bool isUnique(char *str) {
	for(int i=0;i<strlen(str)-1;i++) {
		if(str[i] == str[i+1]) break;
		return false;
	}
	return true;
}

int main(){
	char str[100]; 
	cin.getline(str, 100);
	// sort(str, str+100);
	if(isUnique(str)) {
		cout<<"unique charecters are there";		
	}else{
		cout<<"no unique charecters are not there";
	}
	return 0;
}