#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    //stack<char> st;
    int ans = 0;
    int count = 0;
    for(auto c : s) {
        if(c == '(') {
            count++;
        } else {
            count--;
        }
        if(count < 0) {
            ans++;
            count = 0;
        }
    }
    ans += count;
    // stack<char> st;
    // int ans = 0;
    // for(auto c : s) {
    //     if(c == '(') {
    //         st.push(c);
    //     } else {
    //         if(st.empty()) {
    //             ans++;
    //         } else {
    //             st.pop();
    //         }
    //     }
    // }
    // ans += st.size();
    cout << ans << endl;

    return 0;
}