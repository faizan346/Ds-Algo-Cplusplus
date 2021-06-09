#include<bits/stdc++.h>
using namespace std;


void solve(string s, int n, int k) {
    unordered_map<int, int> fre;
    for(auto c : s) {
        fre[c] = 0;
    }
    int j = -1;
    int len = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(fre[c] == 0) count++;
        fre[c]++;
        while(j < i && count > k) {
            j++;
            char c = s[j];
            if(fre[c] == 1) count--;
            fre[c]--;
        }
        len = max(len, i-j);
    }
    cout << len << endl;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    solve(s, s.size(), k);
    return 0;
}