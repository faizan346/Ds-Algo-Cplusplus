#include<bits/stdc++.h>
using namespace std;

void distinctSubSeq(string s) {
    vector<long long> dp(s.size()+1, 0);
    dp[0] = 1; // null
    unordered_map<char, int> umap; // stores dp ind for char, uses when encounter same char again
    for(int i = 1; i < dp.size(); i++) {
        dp[i] = 2 * dp[i-1];
        char ch = s[i-1];
        if(umap.count(ch)) {
            int repeatingInd = umap[ch];
            dp[i] = dp[i] - dp[repeatingInd - 1];
        }
        umap[ch] = i;
    }
    cout << dp[s.size()] - 1 << endl; // remove null char count..
}

int main() {
    string s;
    cin >> s;
    distinctSubSeq(s);
    return 0;
}