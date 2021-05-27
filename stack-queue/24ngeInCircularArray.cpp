#include<bits/stdc++.h>
using namespace std;

void ngeCircular(vector<int>& a, vector<int>& ans) {
    int n = a.size();
    int maxInd = 0;
    for(int i = 1; i < n; i++) {
        if(a[maxInd] < a[i]) maxInd = i;
    }
    stack<int> st;
    int startInd = (maxInd-1+n) % n;
    st.push(a[maxInd]);
    ans[maxInd] = -1;
    for(int i = startInd; i != maxInd; i = (i-1+n) % n) {
        while(!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        if(st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(a[i]);
    }
}

int main() {
    int n; 
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n, 0);
    ngeCircular(a, ans);
    cout << n << endl;
    for(auto x : ans) cout << x << endl;
    return 0;
}