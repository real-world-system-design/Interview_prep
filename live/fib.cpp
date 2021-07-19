#include <iostream>
using namespace std;

//it is basically a pattern of numbers where the sum of previous two nums are the sum of 
//third one .

// 0 1 1 2 3 5 8 13

int fibo(int n) {

   int a = 0;
   int b = 1;
   
   cout<<a<<" ";
   cout<<b<<" ";

   for(int i = 0; i < n -2 ;i++) {
   	int c = a+b;
   	//1 + 1 = 2
   	cout<<c<<" ";
   	a = b;
   	//a = 1
   	b = c;
   	//b = 2
   }
}

int main() {

	fibo(5);

	return 0;
}