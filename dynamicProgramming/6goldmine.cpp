#include<bits/stdc++.h>
using namespace std;

int goldMineMax(vector<vector<int>>& mine, int i, int j, vector<vector<int>>& t) {
    if(i == mine.size() || i == -1) { // when boundary cross just assign min valu.
        return INT_MIN;
    }
    if(j == mine[0].size()-1) { // if at last col assign same value
        return t[i][j] = mine[i][j];
    }
    if(t[i][j] != -1) {
        return t[i][j];
    }
    int top = goldMineMax(mine, i-1, j+1, t);
    int mid = goldMineMax(mine, i, j+1, t);
    int bottom = goldMineMax(mine, i+1, j+1, t);
    return t[i][j] = mine[i][j] + max(max(top, mid), bottom);
}

int goldMineMax(vector<vector<int>>& mine) {
    int dp[mine.size()][mine[0].size()];
    for(int j = mine[0].size()-1; j >= 0; j--) {
        for(int i = 0; i < mine.size(); i++) {
            if(j == mine[0].size()-1) {
                dp[i][j] = mine[i][j];
            } else if(i == 0){
                dp[i][j] = mine[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            } else if(i == mine.size()-1) {
                dp[i][j] = mine[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            } else {
                dp[i][j] = mine[i][j] + max(max(dp[i][j+1],dp[i+1][j+1]), dp[i-1][j+1]);
            }
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < mine.size(); i++) {
        if(max < dp[i][0]) max = dp[i][0];
    }
    return max;
}

// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
// 33

int main() {
    int n, m;
    cin >> n;
    m = n;
    vector<vector<int>> mine;
    for(int i = 0; i < n; i++) {
        mine.push_back(vector<int>());
        for(int j = 0; j < m; j++) {
            int v;
            cin >> v;
            mine[i].push_back(v);
        }
    }
    cout << goldMineMax(mine) << endl;
    vector<vector<int>> t(n, vector<int>(m,-1));
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        int cost = goldMineMax(mine, i, 0, t);
        if(max < cost) max = cost;
    }
    cout << max << endl;
    return 0;
}