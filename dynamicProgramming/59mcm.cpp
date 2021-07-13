#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(n-1 , vector<int>(n-1, 0));
    for(int g = 0; g < n-1; g++) {
        for(int i = 0, j = g; j < n-1; j++, i++) {
            if(g == 0) {
                dp[i][j] = 0;
            } else {
                int val = INT_MAX;
                for(int k = i; k < j; k++) {
                    int mulCost = a[i]*a[k+1]*a[j+1];
                    val = min(val, mulCost + dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] = val;
            }
        }
    }
    return dp[0][dp.size()-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << mcm(a) << endl;
    return 0;
}