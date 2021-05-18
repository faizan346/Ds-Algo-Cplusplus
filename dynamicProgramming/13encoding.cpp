#include<bits/stdc++.h>
using namespace std;

int encoding(string& s, int i, vector<int>& t) {
    if(i == s.size()) return 1;
    if(i > s.size()) return 0;
    if(s[i] == '0') return 0;
    int a = encoding(s, i+1, t);
    int b = (s.substr(i,2) < "26") ? encoding(s, i+2, t) : 0;
    int codes = a + b;
    return codes;
}

int encoding(string& s) {
    vector<int> t(s.size() + 1, 0);
    t[0] = 1;
    t[1] = 1;
    for(int i = 2; i < t.size(); i++) {
        if(s[i-1] != '0') {
            t[i] = t[i-1];
        }
        if(s.substr(i-2, 2) < "26" && s[i-2] != '0') {
            t[i] += t[i-2];
        }
    }
    return t[s.size()];
}

int main() {
    string s;
    cin >> s;
    cout << encoding(s) << endl;
    vector<int> t(s.size()+1, -1);
    cout << encoding(s, 0, t) << endl;
    return 0;
}