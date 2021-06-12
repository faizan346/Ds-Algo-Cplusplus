#include<bits/stdc++.h>
using namespace std;

void wildcardPattern(string a, string b) {
    int n = b.size();
    int m = a.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    for(int i = 0; i < n+1; i++) {
       // cout << ((i == 0) ? '_' : b[i-1]) << " => ";
        for(int j = 0; j < m+1; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            } else if(j == 0) {
                if(i > 0 && b[i-1] == '*') {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = false;
                }
            } else {
                char cb = b[i-1];
                char ca = a[j-1];
                if(cb == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(cb == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = (cb == ca) && dp[i-1][j-1];
                }
            }
            //cout << ((dp[i][j]) ? "true" : "false") << " ";
        }
        //cout << endl;
    }
    // for(auto y : dp) {
    //     for(auto x : y) cout << ((x) ? "true" : "false") << " ";
    //     cout << endl;
    // }
    cout << (dp[n][m] ? "true" : "false") << endl;
}

int main() {
    string a, b;
    cin >> a >> b;
    wildcardPattern(a, b);
}