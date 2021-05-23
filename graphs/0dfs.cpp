#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* graph, int src, vector<bool>& visited) {
    if(visited[src]) return;
    visited[src] = true;
    cout << src << " ";
    for(auto des : graph[src]) {
        dfs(graph, des, visited);
    }
}

int main() {
    int n, v;
    cin >> v >> n;
    vector<int> graph[n];
    for(int i = 0; i < n; i++) {
        int src, des;
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    int src;
    cin >> src;
    vector<bool> visited(v, false);
    dfs(graph, src, visited);
    cout << endl;
    return 0;
}

// 7
// 8
// 0 1
// 0 3
// 3 2
// 1 2
// 1 4
// 4 5
// 4 6
// 5 6
// 2