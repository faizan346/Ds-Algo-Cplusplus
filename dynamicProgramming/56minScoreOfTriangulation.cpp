#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 2; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            dp[i][j] = INT_MAX;
            // taking base in abcde -> ae (first-last)
            int ae = v[i] * v[j];
            for(int k = i+1; k < j; k++) {
                int ake = ae * v[k]; // base triangle
                int cost = dp[i][k] + dp[k][j] + ake;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}