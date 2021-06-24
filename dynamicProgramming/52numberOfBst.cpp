#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = 1;
            } else {
                for(int k = i; k <= j; k++) {
                    if(k == i) {
                        dp[i][j] += dp[i+1][j];
                    } else if(k == j) {
                        dp[i][j] += dp[i][j-1];
                    } else {
                        dp[i][j] += dp[i][k-1] * dp[k+1][j];
                    }
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
    // same as catalan number but i  did this way to make it more clear for myself
    return 0;
}