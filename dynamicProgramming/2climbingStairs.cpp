#include<bits/stdc++.h>
using namespace std;

int climbingStairsMemo(int n, int *t) {
    if(n == 0) return 1;
    if(t[n] != -1) {
        return t[n];
    }
    int paths = 0;
    for(int i = n; i > 0; i--) {
        paths += climbingStairsMemo(n-i, t);
    }
    return t[n] = paths;
}

int climbingStairstabulation(int n) {
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; //one way if n = 1 that is don't move.
    for(int i = 1; i <= n; i++) {
        for(int j = i; j > 0; j--) {
            dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    int t[n+1];
    memset(t, -1, sizeof(t));
    cout << climbingStairsMemo(n, t) << endl;
    cout << climbingStairstabulation(n) << endl;
    return 0;
}