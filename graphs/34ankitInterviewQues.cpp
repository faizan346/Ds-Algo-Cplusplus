#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;
    Edge(int s, int n, int w) {
        src = s; nbr = n; wt = w;
    }
};

int minDistance(vector<int>& dist, vector<bool>& visited) {
    int m = INT_MAX;
    int index = 0;
    for(int v = 0; v < dist.size(); v++) {
        if(!visited[v] && m > dist[v]) {
            m = dist[v], index = v;
        } 
    }
    return index;
}

void dijkstra(vector<vector<Edge>>& graph, int src, int des, vector<int> &par, vector<bool> &visited) {
    int v = graph.size();
    vector<int> dist(v, INT_MAX);

    dist[src] = 0;
    for(int i = 0; i < v-1; i++) { // v-1 iteration becoz last unvisited vertex won't have any neighbor to visit
        int u = minDistance(dist, visited);
        visited[u] = true;
        for(auto e : graph[u]) {
            if(!visited[e.nbr] && dist[u] != INT_MAX) {
                dist[e.nbr] = min(dist[e.nbr], dist[u] + e.wt);
                par[e.nbr] = u;
            }
        }
    }
    int u = des;
    while(u != -1) {
        cout << u << " ";
        u = par[u];
    }
    cout << endl;
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<vector<Edge>> graph(v, vector<Edge>());
    for(int i = 0; i < n; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(src, nbr, wt));
        graph[nbr].push_back(Edge(nbr, src, wt));
    }
    int src, des; 
    cin >> src >> des;
    vector<int> par(n, -1);
    vector<bool> visited(v, false);
    dijkstra(graph, src, des, par, visited);
    visited = vector<bool>(v, false);
    int u = par[des];
    while(u != src) {
        visited[u] = true;
        u = par[u];
    }
    par = vector<int>(n, -1);
    dijkstra(graph, des, src, par, visited);
}

// 7 9
// 0 1 10
// 0 3 40
// 1 2 10
// 3 2 10
// 3 4 2
// 4 5 3
// 4 6 8
// 5 6 3
// 2 5 3 
// 0 5

// 5 2 1 0 
// 0 3 4 5 
