#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>>& graph, int i, int j, string& s, char c) {
    if(i < 0 || j < 0 || i == graph.size() || j == graph[0].size() || graph[i][j] != 1) 
        return;
    graph[i][j] = -1;
    s += c; // during preorder
    dfs(graph, i+1, j, s, 'd');
    dfs(graph, i, j+1, s, 'r');
    dfs(graph, i-1, j, s, 'u');
    dfs(graph, i, j-1, s, 'l');
    s += "B"; // during postorder backtrack symbol
    // both these sturcture mapping garantee different maps.
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
    unordered_set<string> structures; // it stores the shapes
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] != 1) continue;
            string s = "";
            dfs(graph, i, j, s, '*');
            if(structures.count(s) == 0) ans++;
            structures.insert(s);
        }
    }
    cout << ans << endl;
    return 0;
}