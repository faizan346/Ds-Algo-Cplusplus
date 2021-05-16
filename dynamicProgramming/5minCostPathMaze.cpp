#include<bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int>>& maze, int i, int j, vector<vector<int>>& t) {
    if(i == maze.size() || j == maze[0].size()) {
        return INT_MAX;
    }
    if(t[i][j] != -1) return t[i][j];
    if(i == maze.size()-1 && j == maze[0].size()-1) {
        return t[i][j] = maze[i][j];
    }
    int vc = minCostPath(maze, i+1, j, t);
    int hc = minCostPath(maze, i, j+1, t);
    return t[i][j] = min(vc, hc) + maze[i][j];
}

int minCostOfPath(vector<vector<int>>& maze, int& n, int& m) {
    int dp[n][m];
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(i == n-1 && j == m-1) { // last block
                dp[i][j] = maze[i][j];
            } else {
                int hc = INT_MAX;
                int vc = INT_MAX;
                if(i < n-1) {
                    vc = dp[i+1][j]; //vertical down solution
                }
                if(j < m-1) {
                    hc = dp[i][j+1]; //horizontal right solution
                }
                dp[i][j] = min(vc, hc) + maze[i][j]; //solution = right sol and down sol ka min + current block cost
            }
        }
    }
    return dp[0][0];
}
// 4
// 1 2 2 1
// 1 2 2 2
// 1 1 1 2
// 2 2 1 1

// 7 8 7 6 
// 6 6 5 5 
// 5 4 3 3 
// 6 4 2 1 
// 7

int main() {
    int n, m;
    cin >> n;
    m = n;
    vector<vector<int>> maze;
    for(int i = 0; i < n; i++) {
        maze.push_back(vector<int>());
        for(int j = 0; j < m; j++) {
            int v;
            cin >> v;
            maze[i].push_back(v);
        }
    }
    cout << minCostOfPath(maze, n, m) << endl;
    vector<vector<int>> t(n, vector<int>(m, -1));
    cout << minCostPath(maze, 0, 0, t) << endl;
    return 0;
}