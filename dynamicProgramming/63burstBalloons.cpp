#include<bits/stdc++.h>
using namespace std;

// we are going to find the the cost of bursting in subarray
// by assuming only one balloon left and other ballons array at left and right are bursted
// eg:-  5 (2 3 5 9) 10
// suppose only 3 left and 2, (5, 9) got bursted and we know their max cost then
// price for 3 as last remaining, would be cost(2) + cost(5,9) + 5 * 3 * 10

int burstBalloons(vector<int> &a, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            int maxCost = INT_MIN;
            for(int k = i; k <= j; k++) { // k-> last rem in subarray of ballong bursting
                int cost = 0;
                int left = k-1;
                int right = k+1;
                // cost of left and riht subarray for bursted balloons
                if(left >= i) cost += dp[i][left];
                if(right <= j) cost += dp[right][j];
                // cost for last remaining ballon in subarray
                int c = a[k];
                if(i-1 >= 0) c *= a[i-1];
                if(j+1 < n) c *= a[j+1];
                cost += c;
                
                maxCost = max(maxCost, cost);
            }
            dp[i][j] = maxCost;
        }
    }
    // for(auto y : dp) {
    //     for(auto x : y) cout << x << " ";
    //     cout << endl;
    // }
    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << burstBalloons(a, n) << endl;
    
    return 0;
}