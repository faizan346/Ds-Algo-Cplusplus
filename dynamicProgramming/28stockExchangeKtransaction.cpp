#include<bits/stdc++.h>
using namespace std;

int stockExchange(vector<int>& a, int n, int k, vector<vector<int>>& t) {
    if(n == 0) return 0;
    if(k == 0) return 0;
    if(t[n][k] != -1) return t[n][k];
    int profit = stockExchange(a, n-1, k, t);
    for(int i = n-1; i >= 1; i--) {
        profit = max(profit, stockExchange(a, i, k-1, t)+a[n-1]-a[i-1]);
    }
    return t[n][k] = profit;
}

int stockExchange(vector<int>& a, int k) {
    vector<vector<int>> dp(k+1, vector<int>(a.size(), 0));
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp[0].size(); j++) {
            dp[i][j] = dp[i][j-1];
            for(int l = 0; l < j; l++) {
                dp[i][j] = max(dp[i][j], dp[i-1][l]+(a[j]-a[l]));
            }
        }
    }
    return dp[k][a.size()-1];
}

int stockExchangeOp(vector<int>& a, int k) {
    vector<vector<int>> dp(k+1, vector<int>(a.size(), 0));
    for(int i = 1; i < dp.size(); i++) {
        //max k - 1 transaction + buy
        int mkmot = INT_MIN;
        for(int j = 1; j < dp[0].size(); j++) {
            mkmot = max(mkmot, dp[i-1][j-1] - a[j-1]);
            dp[i][j] = max(dp[i][j-1], mkmot + a[j]);
        }
    }
    return dp[k][a.size()-1];
}

// 6
// 9 6 7 6 3 8
// 3

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    int k;
    cin >> k;
    cout << stockExchange(a, k) << endl;
    cout << stockExchangeOp(a, k) << endl;
    vector<vector<int>> t(a.size()+1, vector<int>(k+1, -1));
    cout << stockExchange(a, a.size(), k, t) << endl;
    return 0;
}