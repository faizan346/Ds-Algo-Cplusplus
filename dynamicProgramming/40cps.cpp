#include<bits/stdc++.h>
using namespace std;

void lps(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int count = 0;
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = 1;
                count++;
            } else {
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    count++;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
    }
    cout << count << endl;
}

void lpsNew(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = 1;
            } else {
                if(s[i] == s[j]) {
                    dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

int main() {
    string s1;
    cin >> s1;
    // lps(s1);
    lpsNew(s1);
    return 0;
}