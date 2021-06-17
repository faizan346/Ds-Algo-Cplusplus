#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    unordered_map<char, int> fre; // fre of remaining characters
    for(auto c : s) {
        if(fre.count(c) == 0) {
            fre[c] = 0;
        }
        fre[c]++;
    }
    unordered_set<char> inc;
    stack<char> st;
    for(auto c : s) {
        fre[c]--; // character used
        if(inc.count(c) == 1) continue;
        // if stack has top has bigger alphabet than curr than pop
        // only if there is more in remaining string
        while(!st.empty() && st.top() > c && fre[st.top()] > 0) {
            inc.erase(st.top());
            st.pop();
        }
        st.push(c);
        inc.insert(c);
    }
    string ans = "";
    while(!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    cout << ans << endl;
    return 0;
}