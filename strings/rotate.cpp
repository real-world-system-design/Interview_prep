#include <iostream>
using namespace std;

void rotate(char *a, int k) {
	int i = strlen(a);
	while(i >= 0) {
		a[i+k] = a[i];
		i--;
	}
	i = strlen(a);
	int s = 0;
	int j = i-k;
	while(j<i) {
		a[s] = a[j];
		j++;
		s++;
	}
	a[i-k] = '\0';
}

int main() {
	char a[100] = "hello";
	int k;
	cin>>k;
	rotate(a, k);
	cout<<a<<endl;
	return 0;
}