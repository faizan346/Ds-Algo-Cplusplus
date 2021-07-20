#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<pair<int, int>> bfs;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) {
                bfs.push({i, j});
            }
        }
    }
    int level = -1;
    while(!bfs.empty()) {
        int l = bfs.size();
        level++;
        while(l-- > 0) {
            pair<int, int> p = bfs.front();
            bfs.pop();
            int i = p.first;
            int j = p.second;
            if(i < 0 || j < 0 || i == n || j == n || grid[i][j] == 2) {
                continue;
            }
            grid[i][j] = 2;
            bfs.push({i+1, j});
            bfs.push({i, j+1});
            bfs.push({i-1, j});
            bfs.push({i, j-1});
        }
    }
    // cout << endl;
    // for(auto y : grid) {
    //     for(auto x : y) cout << x << " ";
    //     cout << endl;
    // }
    cout << (level-1 == 0 ? -1 : level - 1)<< endl;
    return 0;
}