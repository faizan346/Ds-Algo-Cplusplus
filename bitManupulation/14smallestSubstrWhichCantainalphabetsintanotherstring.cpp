#include<bits/stdc++.h>
using namespace std;

void solve(string s, string sm) {
    int b = 0;
    for(auto ch : sm) {
        b = (b | 1 << (ch - 'a'));
    }
    int start = -1, end = -1;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            if(g == 0) {
                dp[i][j] = (1 << (s[i] - 'a'));
            } else {
                dp[i][j] = (dp[i+1][j] | dp[i][j-1]);
            }
            if((dp[i][j] & b) == b) {
                start = i;
                end = j;
                break;
            }
        }
        if(start != -1) break;
    }
    if(start == -1) {
        cout << "";
    } else {
        for(int i = start; i <= end; i++) {
            cout << s[i];
        }
    }
    
    cout << endl;
    
}
// made by faizan the great

int main() {
    string s, sm;
    cin >> s >> sm;
    solve(s, sm);
}