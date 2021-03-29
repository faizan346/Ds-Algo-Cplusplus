#include<bits/stdc++.h>
using namespace std;

int joseph(int n, int k) {
    if(n == 1) { // when only one element than it will be the remaining one
        return 0; //return idx of only element.
    }
    //survivor index left after execution of n-1 term
    int i = joseph(n-1, k);
    //map index i to rem n-1 numbers rem after execution of kth term in n numbers
    int survivor = (i+k)%n;
    return survivor;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << joseph(n, k) << endl;
    return 0;
}