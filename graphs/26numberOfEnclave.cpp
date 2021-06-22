#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& graph, int i, int j, int& count, vector<vector<bool>>& visited) {
    if(i < 0 || j < 0 || i == graph.size() || j == graph[0].size()) {
        count = -1;
        return;
    }
    if(graph[i][j] == 0 || visited[i][j]) return;
    visited[i][j] = true;
    if(count == -1) return;
    count++;
    // dfs
    dfs(graph, i+1, j, count, visited);
    dfs(graph, i-1, j, count, visited);
    dfs(graph, i, j+1, count, visited);
    dfs(graph, i, j-1, count, visited);
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
    
    int enclave = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] != 0 && !visited[i][j]) {
                int count = 0;
                dfs(graph, i, j, count, visited);
                enclave += count == -1 ? 0 : count;
            }
        }
    }
    cout << enclave << endl;
    return 0;
}

