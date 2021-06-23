#include<iostream>
using namespace std;

//we can perform three operations on the string insert, replace and delete 
//But we have only one chance left 

bool oneEditReplace(char *str1, char * str2) {
	bool foundDifference = false;
	for(int i=0;i<strlen(str1);i++) {
		if(str1[i] != str2[i]) {
			if(foundDifference) {
				return false;
			}
			foundDifference = true;
		}
	}
	return true;
}

bool oneEditInsert(char *str1, char *str2) {
	int index1 = 0;
	int index2 = 0;
	while(index2 < strlen(str2) && index1 < strlen(str1)) {
		if(str1[index1] != str2[index2]) {
			if(index1 != index2) {
				return false;
			}
			index2++;
		}else{
			index1++;
			index2++;
		}
	}
	return true; 
}

bool isOneAway(char *str1, char *str2) {
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	if(l1 == l2) {
		return oneEditReplace(str1, str2);
	} else if(l1 - 1 == l2) {
		return oneEditInsert(str1, str2);
	} else if(l1 + 1 == l2) {
		return oneEditInsert(str1, str2);
	}
	return false;
}

int main() {
	char str1[100];
	char str2[200];
	cin.getline(str1, 100);
	cin.getline(str2, 100);
	
	if(isOneAway(str1, str2)) {
		cout<<"true";
	}else{
		cout<<"false";
	}
	return 0;
}