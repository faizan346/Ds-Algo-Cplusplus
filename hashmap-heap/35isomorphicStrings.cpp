#include<bits/stdc++.h>
using namespace std;

bool solve(string &a, string &b) {
    int n = a.size();
    unordered_map<char, char> ua;
    unordered_set<char> sb;
    for(int i = 0; i < n; i++) {
        char ca = a[i];
        char cb = b[i];
        if(ua.count(ca) == 0) {
            if(sb.count(cb) == 0) {
                ua[ca] = cb;
                sb.insert(cb);
            } else {
                return false;
            }
        } else {
            if(cb != ua[ca]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    cout << (solve(a, b) ? "true" : "false") << endl;
    return 0;
}