#include<bits/stdc++.h>
using namespace std;

int firstOccurance(int *a, int n, int i, int o) {
    if(i == n) {
        return -1;
    }
    if(a[i] == o) {
        return i;
    } else {
        return firstOccurance(a, n, i+1, o);
    }
}

int lastOccurance(int *a, int n, int o) {
    if(n == 0) {
        return -1;
    }
    if(a[n-1] == o) {
        return n-1;
    } else {
        return lastOccurance(a, n-1, o);
    }
}

void allOccurance(int *a, int n, vector<int> &v, int o) {
    if(n == 0) {
        return;
    }
    allOccurance(a, n-1, v, o);
    if(a[n-1] == o) {
        v.push_back(n-1);
    }
}

int* allOccuranceStatic(int *a, int n, int o, int foundSoFar) {
    if(n == 0) {
        return new int[foundSoFar];
    }
    if(a[n-1] == o) {
         int *b = allOccuranceStatic(a, n-1, o, foundSoFar+1);
         b[foundSoFar] = n-1;
         return b;
    } else {
        int *b = allOccuranceStatic(a, n-1, o, foundSoFar);
        return b;
    }
}

int main() {
    int n, o;
    cin >> n >> o;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << firstOccurance(a, n, 0, o) << endl;
    cout << lastOccurance(a, n, o) << endl;
    vector<int> v;
    allOccurance(a, n, v, o);
    for(auto x : v) {
        cout << x << " ";
    }
    cout << endl;
    int *b = allOccuranceStatic(a, n, o, 0);
    for(int i = 0; i < 2; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}