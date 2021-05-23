#include<bits/stdc++.h>
using namespace std;

int obst(vector<int>& keys, vector<int>& freq, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            if(g == 0) {
                dp[i][j] = freq[i];
            } else {
                int minCost = INT_MAX;
                int levelUpCost = 0;
                for(int k = i; k <= j; k++) {
                    int cost = 0;
                    // left side
                    if(k != i) {
                        cost += dp[i][k-1];
                    }
                    // right side
                    if(k != j) {
                        cost += dp[k+1][j];
                    }
                    // save the cost for curr BST for given keys if minimum
                    minCost = min(minCost, cost);
                    // common levelUp Cost
                    levelUpCost += freq[k];
                }
                minCost += levelUpCost;
                dp[i][j] = minCost;
            }
        }
    }
    return dp[0][n-1];
}
// 4
// 10 20 30 40
// 3 1 2 1
// 13
int main() {
    int n;
    cin >> n;
    vector<int> keys;
    vector<int> freq;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        keys.push_back(v);
    }
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        freq.push_back(v);
    }
    cout << obst(keys, freq, n) << endl;
    return 0;
}