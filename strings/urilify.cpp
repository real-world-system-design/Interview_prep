#include<iostream>
#include<cstring>
using namespace std;

void replace(char *a){
	int l = strlen(a);
	int spaces = 0;
	for(int i=0;i < l; i++) {
		if(a[i] == ' ') {
			spaces++;
		}
	}
	int idx = l + 2*spaces;
	a[idx] = '\0';

	for(int i=l-1;i>=0;i--) {
		if(a[i] == ' '){
			//%20 goes here
			a[idx-1] = '0';
			a[idx-2] = '2';
			a[idx-3] = '%';
			idx = idx - 3;
		}else{
			a[idx-1] = a[i];
			idx--;
		}
	}

}

int main() {
	char a[100];
	cin.getline(a, 100);
	replace(a);
	cout<<a<<endl;

	return 0;
}