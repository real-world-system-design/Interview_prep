//primae number is a numebr which is the multiple of 1 and that number
#include<iostream>
using namespace std;

bool isPrime(int num) {
    bool isP = true;
    for(int i =2; i<=num/2; i++)
       if(num%i == 0) {
        isP = false;
        break;
       }
       if(num < 2) {
           isP = false;
       }
    return isP; 
}

int main() {

    int num;
    cin>>num;

    if( isPrime(num) ) {
        cout<<"Prime"<<endl;
    }else{
        cout<<"Not prime"<<endl;
    }

    return 0;
}