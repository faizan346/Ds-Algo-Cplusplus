#include<bits/stdc++.h>
using namespace std;

int palindromicSubStrings(string s) {
    int n = s.size();
    bool dp[n][n];
    int count = 0;
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++,j++) {
            if(g == 0) {
                dp[i][j] = true;
            } else if(g == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            }
            if(dp[i][j] == true) count++;
        }
    }
    // unordered_map<char, int> umap;
    // int extra = 0;
    // for(auto c : s) {
    //     if(umap.find(c) == umap.end()) {
    //         umap[c] = 1;
    //     } else {
    //         extra++;
    //     }
    // }
    // count = count - extra;
    return count;
}

int main() {
    string s;
    cin >> s;
    cout << palindromicSubStrings(s) << endl;
}