#include<bits/stdc++.h>
using namespace std;

void dps(string s) {
    int n = s.size();
    unordered_map<char, int> umap; // char pre ind
    vector<int> pre(n, 0);
    for(int i = 0; i < n; i++) {
        if(umap.count(s[i])) {
            pre[i] = umap[s[i]];
        } else {
            pre[i] = -1;
        }
        umap[s[i]] = i;
    }
    umap.clear(); // char next ind
    vector<int> next(n, 0);
    for(int i = n-1; i >= 0; i--) {
        if(umap.count(s[i])) {
            next[i] = umap[s[i]];
        } else {
            next[i] = -1;
        }
        umap[s[i]] = i;
    }
    // dp stores the distinct palindromic subsequnce between i-j
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = 1;
            } else {
                if(s[i] == s[j]) {
                    int n = next[i];
                    int p = pre[j];
                    if(n > p) { // no matching character in between
                        dp[i][j] = 2 * dp[i+1][j-1] + 2;
                    } else if(n == p) { // one repeat ch in between
                        dp[i][j] = 2 * dp[i+1][j-1] + 1;
                    } else if(n < p) { // two or greater repeat ch in between
                        dp[i][j] = 2 * dp[i+1][j-1] - dp[n+1][p-1];
                    }
                } else {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}

int main() {
    string s;
    cin >> s;
    dps(s);
    return 0;
}