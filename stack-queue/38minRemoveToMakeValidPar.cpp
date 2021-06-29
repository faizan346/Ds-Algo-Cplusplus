#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<pair<char, int>> st;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '(') {
            st.push({'(', i});
        } else if(c == ')') {
            if(!st.empty() && st.top().first == '(') {
                st.pop();
            } else {
                st.push({')', i});
            }
        }
    } 
    string ans = "";
    for(int i = s.size()-1; i >= 0; i--) {
        if(!st.empty() && st.top().second == i) {
            st.pop();
        } else {
            ans = s[i] + ans;
        }
    }
    cout << ans << endl;
}