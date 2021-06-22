#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int n , int m) {
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 2) q.push({{i, j}, 0});
        }
    }
    int hours = 0;
    while(!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first, j = p.first.second;
        int h = p.second;
        if(i < 0 || j < 0 || i == n || j == m || graph[i][j] == 0) continue;
        graph[i][j] = 0;
        hours = max(hours, h);
        h = h + 1;
        q.push({{i+1,j}, h});
        q.push({{i,j+1}, h});
        q.push({{i-1,j}, h});
        q.push({{i,j-1}, h});
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 1) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << hours << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    
    bfs(graph, n, m);
    
}