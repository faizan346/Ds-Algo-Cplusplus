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
    int index;
    for(int v = 0; v < dist.size(); v++) {
        if(!visited[v] && m > dist[v]) {
            m = dist[v], index = v;
        } 
    }
    return index;
}

void dijkstra(vector<vector<Edge>>& graph, int src) {
    int v = graph.size();
    vector<bool> visited(v, false);
    vector<int> dist(v, INT_MAX);

    dist[src] = 0;
    for(int i = 0; i < v-1; i++) { // v-1 iteration becoz last unvisited vertex won't have any neighbor to visit
        int u = minDistance(dist, visited);
        visited[u] = true;
        for(auto e : graph[u]) {
            if(!visited[e.nbr]) {
                dist[e.nbr] = min(dist[e.nbr], dist[u] + e.wt);
            }
        }
    }
    
    for(int i = 1; i < v; i++) {
        cout << i << "      " << dist[i] << endl;
    }
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
    int src; 
    cin >> src;
    dijkstra(graph, src);
}