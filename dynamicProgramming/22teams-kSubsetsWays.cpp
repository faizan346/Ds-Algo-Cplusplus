#include<bits/stdc++.h>
using namespace std;

int teams(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            if(j == 1) {
                dp[i][j] = 1;
            } else if(i == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j-1] * 1 + dp[i-1][j] * j;
            }
        }
    }
    for(auto y : dp) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
    return dp[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << teams(n, k) << endl;
    return 0;
}