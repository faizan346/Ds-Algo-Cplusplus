#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    vector<int> dp(n+1, 0);
    dp[1] = cost[1];
    for(int i = 2; i < n+1; i++) {
        dp[i] = cost[i]; // max price without cutting
        int li = 1;
        int ri = i - 1;
        while(li <= ri) { // if cutting max price to val
            dp[i] = max(dp[i], dp[li]+dp[ri]);
            li++, ri--;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

// 8

// 1   
// 5   
// 8   
// 9  
// 10 
// 17  
// 17  
// 20

// 22