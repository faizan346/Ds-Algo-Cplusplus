#include<bits/stdc++.h>
using namespace std;

void displayObst(vector<vector<int>> &root, int i, int j) {
    if(i > j) return;
    int k = root[i][j];
    if(i <= k-1) cout << root[i][k-1];
    cout << "-->" << k << "<--";
    if(k+1 <= j) cout << root[k+1][j];
    cout << endl;
    displayObst(root, i, k-1);
    displayObst(root, k+1, j);
}

void obst(int n, vector<int> &keys, vector<int> &fre) {
    vector<vector<int>> dp(n, vector<int>(n, 0)); // stores min cost for each subarray
    vector<vector<int>> root(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; j++, i++) {
            if(g == 0) {
                dp[i][j] = fre[i] * 1;
                root[i][j] = i;
            } else {
                int levelUpCost = 0; // fre cost for adding level to all nodes
                int minCost = INT_MAX;
                for(int k = i; k <= j; k++) { // choose root
                    levelUpCost += fre[k];
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
                    if(minCost > cost) {
                        minCost = cost;
                        root[i][j] = k;
                    }
                }
                dp[i][j] = minCost + levelUpCost;
            }
        }
    }
    displayObst(root, 0, n-1);
    for(auto y : root) {
        for(auto x : y) cout << x << " ";
        cout << endl;
    }
    cout << dp[0][n-1] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> keys(n, 0);
    vector<int> fre(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> fre[i];
    }
    
    obst(n, keys, fre);
    return 0;
}