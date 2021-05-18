#include<bits/stdc++.h>
using namespace std;
// 1+(....realstring....)
int noConsecutiveZero(int n, int startWith, vector<vector<int>>& t) {
    if(n == 0) {
        return 1; // empty string one way
    }
    if(t[n][startWith] != -1) return t[n][startWith];
    int ways;
    if(startWith == 1) {
        //if prev element not zero then put curr as zero and one
        ways = noConsecutiveZero(n-1, 1, t)
            + noConsecutiveZero(n-1, 0, t);
    } else {
        ways = noConsecutiveZero(n-1, 1, t);
    }
    return t[n][startWith] = ways;
}

//constant space
int noConsecutiveZero(int n) {
    int zero = 1, one = 1; // ways possible when no element there is one i.e. empty string.
    for(int i = 1; i < n+1; i++) {
        int temp = zero;
        zero = one; // if put curr ele put as zero the next can only be one
        one = one + temp; // if put curr ele put as one next element can be one or zero
    }
    return one;
}

int main() {
    int n;
    cin >> n;
    cout << noConsecutiveZero(n) << endl;
    vector<vector<int>> t(n+1, vector<int>(2, -1));
    cout << noConsecutiveZero(n, 1, t) << endl;

    return 0;
}