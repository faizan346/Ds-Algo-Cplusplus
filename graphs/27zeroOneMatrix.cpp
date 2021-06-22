#include<bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited) {
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[0].size(); j++) {
            if(graph[i][j] == 0) q.push({{i, j}, 0});
        }
    }
    while(!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first, j = p.first.second;
        int dist = p.second;
        if(i < 0 || j < 0 || i == graph.size() || j == graph[0].size() || visited[i][j]) continue;
        visited[i][j] = true;
        graph[i][j] += dist;
        q.push({{i+1, j}, graph[i][j]});
        q.push({{i, j+1}, graph[i][j]});
        q.push({{i-1, j}, graph[i][j]});
        q.push({{i, j-1}, graph[i][j]});
    }
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
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bfs(graph, visited);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

