#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int src, int d, vector<bool> &visited
            , vector<int> &par, vector<int> &disc, vector<int> &low, vector<bool> &ap, bool &isSrcAp) {
                
    visited[src] = true;
    disc[src] = low[src] = d;
    int count = 0;
    for(auto nbr : graph[src]) {
        if(par[src] == nbr) { // check parent path
            continue; 
        } else if(visited[nbr] == true) { // check nbr of visited path
            low[src] = min(low[src], disc[nbr]); 
        } else { // check nbr of unvisited path
            par[nbr] = src;
            count++;
            dfs(graph, nbr, d+1, visited, par, disc, low, ap, isSrcAp); // cal values for unvisited nbr
            if(par[src] == -1) {
                if(count >= 2) isSrcAp = true;
            }
            low[src] = min(low[src], low[nbr]); // than check if nbr can reach smaller low
            if(low[nbr] >= disc[src]) {
                ap[src] = true;
            }
        }
    }
}


int articulation(vector<vector<int>> &graph, int n, int m) {
    vector<bool> ap(n, 0);
    vector<int> par(n, 0), disc(n, 0), low(n, 0);
    vector<bool> visited(n, false);
    int src = 0; // random source;
    par[0] = -1;
    bool isSrcAp = false;
    int order = 1; // order = 1 -> n
    dfs(graph, src, order, visited, par, disc, low, ap, isSrcAp);
    int count = 0;
    for(auto x : ap) {
        if(x == true) count++;
    }
    if(isSrcAp == true) return count;
    return count-1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    for(int i = 0; i < m; i++) {
        int src, nbr;
        cin >> src >> nbr;
        graph[src-1].push_back(nbr-1);
        graph[nbr-1].push_back(src-1);
    }
    cout << articulation(graph, n, m) << endl;
    return 0;
}