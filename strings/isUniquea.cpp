#include<iostream>
#include<algorithm>
using namespace std;

// bool isUnique(char *str) {
// 	for(int i=0;i<strlen(str)-1;i++) {
// 		if(str[i] == str[i+1]) break;
// 		return false;
// 	}
// 	return true;
// }

bool isUniqueTwoPointer(char * str) {
	int i = 0;
	int j = strlen(str) - 1;
	while(i<=j) {
		if(str[i] == str[j]){
			return false;
		}else{
			i++;
			j--;
		}
	}
	return true;
}

int main(){
	char str[100]; 
	cin.getline(str, 100);
	sort(str, str+100);
	if(isUniqueTwoPointer(str)) {
		cout<<"unique charecters are there";		
	}else{
		cout<<"no unique charecters are not there";
	}
	return 0;
}