#include<iostream>
using namespace std;

int factor(int n) {
    int ans = 1;
    for(int i = n; i > 1; i--)
        ans *= i;
    return ans;
}

int main() {

    int n;
    cin >> n;

    cout << factor(n) << endl;

    return 0;
}