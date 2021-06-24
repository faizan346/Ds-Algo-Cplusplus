#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int n = k - 2;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i < n+1; i++) {
        for(int j = 0; j < i; j++) {
            int triangulatedLeft = j;
            int triangulatedRight = i - 1 -j;
            dp[i] += dp[triangulatedLeft] * dp[triangulatedRight];
        }
    }
    cout << dp[n];
}