#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = n;
    stack<int> st;
    for(auto x : a) {
        while(!st.empty() && st.top() > x) {
            st.pop();
        }
        ans += st.size();
        st.push(x);
    }
    cout << ans;
    return 0;
}