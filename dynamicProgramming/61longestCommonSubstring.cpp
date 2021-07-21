#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string &a, string &b) {
    int n = a.size(), m = b.size();
    int len = 0;
    int s = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n+1; i++) { // a
        for(int j = 0; j < m+1; j++) { // b;
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(len < dp[i][j]) {
                        len = dp[i][j];
                        s = i - len;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    for(int i = s; i < s + len; i++) cout << a[i];
    cout << endl;
    return len;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubstring(a, b) << endl;
}