#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
    unordered_map<char, int> freq;
    for(auto c : s) {
        if(freq.count(c) == 0) {
            freq[c] = 0;
        }
    }
    int j = 0;
    int len = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        freq[c]++; 
        // release if needed.
        while(freq[c] > 1 && j < i) {
            char c = s[j];
            freq[c]--;
            j++;
        }
        
        if(len < i-j+1) {
            len = i-j+1;
        }
    }
    cout << len << endl;
}

int main() {
    string s;
    cin >> s;
    solve(s);
}