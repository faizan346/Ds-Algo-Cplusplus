#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &a, int n) {
    vector<int> preMul(n, 0);
    preMul[0] = a[0];
    vector<int> postMul(n, 0);
    postMul[n-1] = a[n-1];
    for(int i = 1; i < n; i++) {
        preMul[i] = a[i] * preMul[i-1];
    }
    for(int i = n-2; i >= 0; i--) {
        postMul[i] = a[i] * postMul[i+1];
    }
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        int val = 1;
        if(i > 0) {
            val *= preMul[i-1];
        }
        if(i < n-1) {
            val *= postMul[i+1];
        }
        ans[i] = val;
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    solve(a, n);
    return 0;
}