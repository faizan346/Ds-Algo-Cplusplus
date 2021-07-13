#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

int solve(string &s) { // n^2 solution
    int n = s.size();
    vector<vector<bool>> pal(n, vector<bool>(n, true));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            if(g == 0) {
                pal[i][j] = true;;
            } else {
                pal[i][j] = s[i] == s[j] && pal[i+1][j-1];
            }
        }
    }
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i < n; i++) { // check suffix for palindrome and min cur for rem string
        if(pal[0][i] == true)  { // if palindrome
            dp[i] = 0; 
            continue;
        }
        int val = INT_MAX;
        for(int k = i; k >= 1; k--) { // suffix check
            if(pal[k][i] == true) {
                val = min(val, dp[k-1] + 1);
            }
        }
        dp[i] = val;
    }
    return dp[n-1];
}

int solve1(string &s) { // n^3 solution
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            if(g == 0) {
                dp[i][j] = 0;
            } else {
                if(isPalindrome(s, i, j)) dp[i][j] = 0;
                else {
                    int val = INT_MAX;
                    for(int k = i; k < j; k++) {
                        val = min(val, dp[i][k] + dp[k+1][j] + 1);
                    }
                    dp[i][j] = val;
                }
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}