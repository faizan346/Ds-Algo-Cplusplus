#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i < n+1; i++) {
        for(int j = 0; j < i; j++) {
            int antiClockWiseDotPair = j;
            int clockWiseDotPair = i - 1 - j;
            dp[i] += dp[antiClockWiseDotPair]*dp[clockWiseDotPair];
        }
    }
    cout << dp[n] << endl;
    return 0;
}