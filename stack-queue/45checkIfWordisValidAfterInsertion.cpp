#include<bits/stdc++.h>
using namespace std;

bool solve(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == 'a') {
            st.push(c);
        } else if(c == 'b') {
            if(!st.empty() && st.top() == 'a') {
                st.pop();
                st.push(c);
            } else {
                return false;
            }
        } else {
            if(!st.empty() && st.top() == 'b') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main() {
    string s;
    cin >> s;
    cout << (solve(s) ? "true" : "false") << endl;
}