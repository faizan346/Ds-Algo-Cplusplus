#include<bits/stdc++.h>
using namespace std;
//o(n/ts) + stack
int coinChange(vector<int>& a, int n, int ts, vector<vector<int>>& t) {
    if(ts < 0) {
        return 0;
    }
    if(t[n][ts] != -1) return t[n][ts];
    if(ts == 0) {
        return t[n][ts] = 1;
    }
    if(n == 0) {
        return t[n][ts] = 0;
    }
    int ways = coinChange(a, n, ts-a[n-1], t) + coinChange(a, n-1, ts, t);
    return t[n][ts] = ways;
}
// o(n)
int coinChange(vector<int>& a, int ts) {
    int dp[ts+1]; // tells the number ways possible in each slot of dp
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // no coins one way
    //whill do n iteration on ts for each coin to fill the ways in dp slots.
    for(int i = 0; i < a.size(); i++) {
        for(int sum = a[i]; sum < ts+1; sum++) {
            dp[sum] += dp[sum-a[i]];
        }
    }
    return dp[ts];
}
// o(nts)
int coinChange(vector<int>& a, int n, int ts) {
    int dp[n + 1][ts + 1];
    for(int i = 0; i < n+1; i++) {
        for(int sum = 0; sum < ts+1; sum++) {
            if(sum == 0) {
                dp[i][sum] = 1;
            } else if(i == 0) {
                dp[i][sum] = 0;
            } else {
                dp[i][sum] = dp[i-1][sum];
                if(sum - a[i-1] >= 0) {
                    dp[i][sum] += dp[i][sum-a[i-1]];
                }
            }
        }
    }
    return dp[n][ts];
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++ ) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    int ts;
    cin >> ts;
    cout << coinChange(a, ts) << endl;
    cout << coinChange(a, n, ts) << endl;
    vector<vector<int>> t(n+1, vector<int>(ts+1, -1));
    cout << coinChange(a, n, ts,  t) << endl;
    for(auto y : t) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
    return 0;
}