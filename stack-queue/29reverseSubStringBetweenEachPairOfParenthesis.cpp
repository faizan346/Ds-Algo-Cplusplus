#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
    stack<char> st;
    for(auto c : s) {
        if(c != ')') {
            st.push(c);
        } else {
            queue<char> q;
            while(st.top() != '(') {
                q.push(st.top());
                st.pop();
            }
            st.pop();
            while(!q.empty()) {
                st.push(q.front());
                q.pop();
            }
        }
    }
    string ans = "";
    while(!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    cout << ans << endl;
}

int main() {
    string s;
    cin >> s;
    solve(s);
    return 0;
}