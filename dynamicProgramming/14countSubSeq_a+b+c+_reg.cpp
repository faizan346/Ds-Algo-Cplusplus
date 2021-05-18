#include<bits/stdc++.h>
using namespace std;

int countSub(string&s, int i, char curr, vector<vector<int>>& t) {
    if(i == s.size() && curr == 'c') {
        return 1;
    }
    if(i == s.size()) return 0;
    if(t[i][curr-'a'] != -1) return t[i][curr-'a'];
    int count;
    if(curr == 'a') {
        if(s[i] == curr) {
            count = countSub(s, i+1, 'a', t) + countSub(s, i+1, 'b', t);
        } else {
            count = countSub(s, i+1, 'a', t);
        }
    } else if(curr == 'b') {
        if(s[i] == curr) {
            count = countSub(s, i+1, 'b', t) + countSub(s, i+1, 'c', t);
        } else {
            count = countSub(s, i+1, 'b', t);
        }
    } else if(curr == 'c') {
        if(s[i] == curr) {
            count = countSub(s, i+1, 'c', t) + 1;
        }
    }
    return t[i][curr-'a'] = count;
}
// bad approach can be done in constant space
int countSub(string& s) {
    vector<vector<int>> dp(4, vector<int>(s.size()+1, 0));
    //when no reg ext we can get only empty string for any lenght
    for(int j = 0; j < dp[0].size(); j++) {
        dp[0][j] = 1;
    }
    //when string has no char than for reg exp except empty string would give 0 string.
    for(int i = 1; i < dp.size(); i++) {
        dp[i][0] = 0;
    }
    for(int reg = 1; reg < dp.size(); reg++) {
        for(int i = 1; i < dp[0].size(); i++) {
            if(reg == 1) {
                if(s[i-1] == 'a') {
                    dp[reg][i] = 2*dp[reg][i-1] + dp[reg-1][i-1];
                } else {
                    dp[reg][i] = dp[reg][i-1];
                }
            } else if(reg == 2) {
                if(s[i-1] == 'b') {
                    dp[reg][i] = 2*dp[reg][i-1] + dp[reg-1][i-1];
                } else {
                    dp[reg][i] = dp[reg][i-1];
                }
            } else if(reg == 3) {
                if(s[i-1] == 'c') {
                    dp[reg][i] = 2*dp[reg][i-1] + dp[reg-1][i-1];
                } else {
                    dp[reg][i] = dp[reg][i-1];
                }
            }
        }
    }
    return dp[3][s.size()];
}

int countSubOn(string& s) {
    int a = 0;
    int ab = 0;
    int abc = 0;

    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if(ch == 'a') {
            a = 2 * a + 1;
        } else if(ch == 'b') {
            ab = 2 * ab + a;
        } else if(ch == 'c') {
            abc = 2 * abc + ab;
        }
    }
    return abc;
}

int main() {
    string s;
    cin >> s;
    cout << countSubOn(s) << endl;
    cout << countSub(s) << endl;
    vector<vector<int>> t(s.size()+1, vector<int>(3,-1));
    int ans = countSub(s, 0, 'a', t);
    cout << ans << endl;
    return 0;
}