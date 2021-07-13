#include<bits/stdc++.h>
using namespace std;

int solve(string &s, string &b) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                bool v = s[i] == 'T' ? true : false;
                dp[i][j][v] = 1;
                dp[i][j][!v] = 0;
            } else {
                for(int k = i; k < j; k++) {
                    char sy = b[k];
                    int dp00 = dp[i][k][0] * dp[k+1][j][0];
                    int dp01 = dp[i][k][0] * dp[k+1][j][1];
                    int dp10 = dp[i][k][1] * dp[k+1][j][0];
                    int dp11 = dp[i][k][1] * dp[k+1][j][1];
                    if(sy == '^') {
                        dp[i][j][1] += dp01 + dp10;
                        dp[i][j][0] += dp11 + dp00;
                    } else if(sy == '|') {
                        dp[i][j][1] += dp10 + dp01 + dp11;
                        dp[i][j][0] += dp00;
                    } else {
                        dp[i][j][1] += dp11;
                        dp[i][j][0] += dp10 + dp00 + dp01;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}

int main() {
    string s, b;
    cin >> s >> b;
    cout << solve(s, b) << endl;
    return 0;
}