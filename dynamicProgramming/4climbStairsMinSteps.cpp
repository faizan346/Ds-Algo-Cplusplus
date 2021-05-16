#include<bits/stdc++.h>
using namespace std;

int minSteps(int i, int n, vector<int>& jumps, vector<int>& t) {
    if(i == n) return 0;
    if(t[i] != -1) return t[i];
    int m = INT_MAX;
    for(int j = 1; j <= jumps[i]; j++) {
        m = min(m, minSteps(i+j, n, jumps, t));
    }
    if(m == INT_MAX) {
        return t[i] = -1;
    } else {
        return t[i] = m + 1;
    }

}

int minSteps(int n, vector<int>& jumps) {
    int dp[n+1]; //min steps to n;
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        dp[i] = INT_MAX;
        for(int j = 1; j <= jumps[i]; j++) {
            if(j+i <= n) {
                dp[i] = min(dp[i], dp[i+j]);
            }
        }
        if(dp[i] == INT_MAX) {
            dp[i] = -1;
        } else {
            dp[i]++;
        }
    }
    for(auto x : dp) cout << x << " ";
    cout << endl;
    return dp[0];
}

int main() {
    int n;
    cin >>n;
    vector<int> jumps;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        jumps.push_back(v);
    }
    cout << minSteps(n, jumps) << endl;
    vector<int> t(n+1, -1);
    cout << minSteps(0, n, jumps, t) << endl;
    for(auto x : t) cout << x << " ";
    cout << endl;
    return 0;
}