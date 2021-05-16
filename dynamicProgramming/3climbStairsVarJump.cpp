#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n, int *jumps) {
    int dp[n+1];
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        dp[i] = 0;
        for(int j = 1; j <= jumps[i]; j++) {
            if(i+j <= n) {
                dp[i] += dp[i+j];
            }
        }
    }
    return dp[0];
}

int climbStairsMemo(int i, int n, int *jumps, int *t) {
    if(i == n) return 1;
    if(i > n) return 0;
    if(t[i] != -1) return t[i];
    int paths = 0;
    for(int j = 1; j <= jumps[i]; j++) {
        int p = climbStairsMemo(i+j, n, jumps, t);
        paths += p;
    }
    return t[i] = paths;
}

int main() {
    int n;
    cin >> n;
    int jumps[n];
    for(int i = 0; i < n; i++) {
        cin >> jumps[i];
    }
    cout << climbStairs(n, jumps) << endl;
    int t[n+1];
    memset(t, -1, sizeof(t));
    cout << climbStairsMemo(0, n, jumps, t) << endl;

    return 0;
}