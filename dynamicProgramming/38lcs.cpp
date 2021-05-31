#include<bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2) {
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
    int i = n;
    int j = m;
    string ans = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans = s1[i-1] + ans;
            i--;
            j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "lcs = " << ans << endl;
    cout << dp[n][m] << endl;
}

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    lcs(s1, s2);
    return 0;
}