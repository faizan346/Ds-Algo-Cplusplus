#include<bits/stdc++.h>
using namespace std;

void lpsUsinglcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < m+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;
}

void lps(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = 1;
            } else {
                if(s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

int main() {
    string s1;
    string s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    // lpsUsinglcs(s1, s2);
    lps(s1);
    return 0;
}