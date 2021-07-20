#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, int i , int j, int &comp) {
    int n = g.size();
    if(i < 0 || j < 0 || i == n || j == n || g[i][j] != 1) return;
    g[i][j] = comp;
    dfs(g, i+1, j, comp);
    dfs(g, i, j+1, comp);
    dfs(g, i-1, j, comp);
    dfs(g, i, j-1, comp);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    
    int comp = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == 1) {
                dfs(g, i, j, comp);
                comp++;
            }
        }
    }
    
    // comp = 2 -> island 1
    // comp = 3 -> island 2
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    int level = 0;
    while(!q.empty()) {
        int l = q.size();
        level++;
        int flag = false;
        while(l-- > 0) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            if(i < 0 || j < 0 || i == n || j == n || g[i][j] == 4) {
                continue;
            }
            if(g[i][j] == 3) {
                flag = true;
                break;
            }
            g[i][j] = 4; // 4 indicate visited;
            q.push({i+1, j});
            q.push({i, j+1});
            q.push({i-1, j});
            q.push({i, j-1});
        }
        if(flag) break;
    }
    
    cout << level - 2 << endl;
    
    return 0;
}