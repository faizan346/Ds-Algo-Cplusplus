#include<bits/stdc++.h>
using namespace std;

bool solve(string &s, vector<string> &a, int n) {
    unordered_map<char, string> ua;
    unordered_set<string> sb;
    for(int i = 0; i < n; i++) {
        char c = s[i];
        string b = a[i];
        if(ua.count(c) == 0) {
            if(sb.count(b) == 0) {
                ua[c] = b;
                sb.insert(b);
            } else {
                return false;
            }
        } else {
            if(b != ua[c]) return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> a(n, "");
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << (solve(s, a, n) ? "true" : "false") << endl;
    return 0;
}