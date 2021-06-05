#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
    stack<int> st;
    for(auto c : s) {
        if(c == '(') {
            st.push(-1);
        } else {
            if(st.top() == -1) {
                st.pop();
                st.push(1);
            } else {
                int x = 0;
                while(st.top() != -1) {
                    x += st.top();
                    st.pop();
                }
                st.pop();
                st.push(2*x);
            }
        }
    }
    int ans = 0;
    while(!st.empty()) {
        ans += st.top();
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