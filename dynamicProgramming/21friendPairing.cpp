#include<bits/stdc++.h>
using namespace std;

int friendPairing(int n) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    int ways = 0;
    ways += friendPairing(n - 1); // when not in pair
    ways += friendPairing(n - 2) * (n - 1); // pair with every other friend
    return ways;
}

int freindPairs(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1; // when no friend one way that is empty;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2] * (i-1);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << freindPairs(n) << endl;
    cout << friendPairing(n) << endl;

    return 0;
}