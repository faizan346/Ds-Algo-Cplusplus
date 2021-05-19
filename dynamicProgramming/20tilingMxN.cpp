#include<bits/stdc++.h>
using namespace std;
// tiles dimenstion h*w = 2*1
//floor dimenstion h*w = 2*vol
int tiling(int m, int n, vector<int>& t) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(t[n] != -1) return t[n];
    int ways = 0; 
    ways = tiling(m, n-1, t) + tiling(m, n-m, t);
    return t[n] = ways;
}

int tiling(int m, int n) {
    int dp[n+1];
    for(int i = 0; i < n+1; i++) {
        if(i < m) {
            dp[i] = 1;
        } else {
            //yah to mth point pr yeh horizontal tha ya toh vertical tha
            //eg ||||  ||__ both are at i = 4
            dp[i] = dp[i-1] + dp[i-m];
        }
    }
    return dp[n];
}

int main() {
    int m,n;
    cin >> m >> n;
    cout <<tiling(m, n) << endl;
    vector<int> t(n+1, -1);
    cout << tiling(m, n, t) << endl;
    return 0;
}