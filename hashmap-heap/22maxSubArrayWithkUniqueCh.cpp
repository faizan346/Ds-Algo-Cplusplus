#include<bits/stdc++.h>
using namespace std;

void solve(string s, int k) {
    unordered_map<char, int> freq;
    for(auto c : s) {
        if(freq.count(c) == 0) {
            freq[c] = 0;
        }
    }
    int count = 0;
    int j = 0;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(freq[c] == 0) count++;
        freq[c]++;
        while(j < i && (count > k)) {
            char ch = s[j];
            if(freq[ch] == 1) count--;
            freq[ch]--;
            j++;
        }
        if(count == k) {
            ans = max(ans, i-j+1);
        }
    }
    cout << ans << endl;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    solve(s, k);
    return 0;
}