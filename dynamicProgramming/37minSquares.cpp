#include<bits/stdc++.h>
using namespace std;

int minSquares(int n) {
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for(int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minSquares(n) << endl;
    return 0;
}