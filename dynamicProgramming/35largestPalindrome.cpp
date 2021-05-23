#include<bits/stdc++.h>
using namespace std;

int largestPalindromicSubString(string s) {
    int n = s.size();
    bool dp[n][n];
    int len = 0;
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++,j++) {
            if(g == 0) {
                dp[i][j] = true;
            } else if(g == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            }
            if(dp[i][j]) {
                len = g+1;
            }
        }
    }

    return len;
}

int main() {
    string s;
    cin >> s;
    cout << largestPalindromicSubString(s) << endl;
}