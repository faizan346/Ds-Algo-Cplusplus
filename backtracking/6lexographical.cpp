#include<bits/stdc++.h>
using namespace std;

void printLexographicalDfs(int i, int n) {
    if(i > n) {
        return;
    }
    cout << i << endl; //print i
    for(int k = 0; k < 9; k++) {
        printLexographicalDfs(10*i+k, n); //if i = 1, faith that it will print family of 11-19
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < 9; i++) {
        printLexographicalDfs(i, n); //print family of every node when first ele 1 - 9
    }
    return 0;
}