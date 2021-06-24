#include<bits/stdc++.h>
using namespace std;

bool solve(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    for(int i = 0; i < m+1; i++) {
        for(int j = 0; j < n+1; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            } else if(j == 0) {
                char c = b[i-1];
                if(c == '*') {
                    dp[i][j] = dp[i-2][j];
                } else {
                    dp[i][j] = false;
                }
            } else {
                char cb = b[i-1];
                char ca = a[j-1];
                if(cb == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(cb == '*') {
                        char pc = b[i-2];
                        if(dp[i-2][j]) {
                            dp[i][j] = true; // when taking it as null (ch *) -> null eg ab*c - > ac
                        } else if(pc == ca || pc == '.') {
                            dp[i][j] = dp[i][j-1]; // check for prev * combination (as* = a, as, ass, asss) for asss when (s == s last characters)
                        }
                } else {
                    if(ca == cb) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
    }
    for(auto y : dp) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
    return dp[m][n];
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << (solve(a, b) ? "true" : "false") << endl;

    return 0;
}