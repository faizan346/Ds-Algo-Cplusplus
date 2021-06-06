#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    for(auto x : a) {
        if(x >= 0) {
            st.push(x);
        } else {
            while(!st.empty() && st.top() >= 0 && st.top() < -x) {
                st.pop();
            }
            if(!st.empty() && st.top() == -x) {
                st.pop();
            } else if(st.empty() || st.top() < 0){
                st.push(x);
            }
        }
    }
    cout << st.size() << endl;
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for(int i = ans.size()-1; i>=0; i--) {
        cout << ans[i] << endl;
    }
    return 0;
}