#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, int *t) {
    if(n == 1 || n == 0) return n;
    if(t[n] != -1) {
        return t[n];
    }
    return t[n] = fibonacci(n-1, t) + fibonacci(n-2, t);
}

int main() {
    int n;
    cin >> n;
    int t[n+1];
    memset(t, -1, sizeof(t));
    cout << fibonacci(n, t) << endl;
    return 0;
}