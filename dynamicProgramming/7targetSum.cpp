#include<bits/stdc++.h>
using namespace std;

bool targetSum(vector<int>& a, int n, int sum, vector<vector<int>>& t) {
    if(sum < 0) {
        return false;
    }
    if(t[n][sum] != -1) return t[n][sum];
    if(sum == 0) {
        return t[n][sum] = true;
    }
    if(n == 0) {
        return t[n][sum] = false;
    }
    bool b1 = targetSum(a, n-1, sum, t);
    bool b2 = targetSum(a, n-1, sum - a[n-1], t);
    return t[n][sum] = b1 || b2;
}

bool targetSum(vector<int>& a, int ts) {
    bool dp[a.size() + 1][ts + 1];
    for(int i = 0; i < a.size()+1; i++) {
        for(int sum = 0; sum < ts+1; sum++) {
            if(sum == 0) {
                dp[i][sum] = true;
            } else if(i == 0) {
                dp[i][sum] = false;
            } else {
                dp[i][sum] = (dp[i-1][sum] == true) || (sum-a[i-1] >= 0 && dp[i-1][sum-a[i-1]]);
            }
        }
    }
    for(int i = 0; i < a.size()+1; i++) {
        for(int j = 0; j < ts+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[a.size()][ts];
}

// 5
// 4 2 7 1 3
// 10
// 1 0 0 0 0 0 0 0 0 0 0 
// 1 0 0 0 1 0 0 0 0 0 0 
// 1 0 1 0 1 0 1 0 0 0 0 
// 1 0 1 0 1 0 1 1 0 1 0 
// 1 1 1 1 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 1 1 1 1 
// 1
// 1

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }
    int ts;
    cin >> ts;
    cout << targetSum(a, ts) << endl;
    vector<vector<int>> t(n+1,vector<int>(ts+1,-1));
    cout << targetSum(a, n, ts, t) << endl;
    return 0;
}