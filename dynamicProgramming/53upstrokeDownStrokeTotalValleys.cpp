#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i < n+1; i++) {
        int num = 0;
        for(int j = 0; j < i; j++) {
            int inside = j;
            int outside = i-1-j;
            num += dp[inside] * dp[outside];
        }
        dp[i] = num;
    }
    cout << dp[n] << endl;
}