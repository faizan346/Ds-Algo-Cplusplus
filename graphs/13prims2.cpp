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


void prims(vector<vector<Edge>>& graph, int src) {
    int v = graph.size();
    vector<bool> visited(v, false);
    vector<int> dist(v, INT_MAX);
    vector<int> par(v, -1);
    dist[src] = 0;
    for(int i = 0; i < v-1; i++) { 
        int u = minDistance(dist, visited);
        visited[u] = true;
        for(auto e : graph[u]) {
            // it actually overrides the min dist array whereas
            // in minheap method we just add this path wt and let 
            // minheap chosse the small one and do not touch the other
            // path wt. so we have multiple paths for same vert rest in minheap
            // wheres in the min dist array the the single path remains for same vert.
            // but it takes o(n) time to choose min but has fast updating speed of o(1)
            // where as in minheap it takes log(n) to insert and to get min val
            // it takes log(n). 
            if(!visited[e.nbr] && dist[e.nbr] > e.wt) {
                dist[e.nbr] = e.wt;
                par[e.nbr] = u;
            }
        }
    }
    cout << "v   u   wt" << endl;
    for(int i = 1; i < v; i++) {
        if(i == src) continue;
        cout << par[i] << "   " << i << "   " << dist[i] << endl;
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
    prims(graph, src);
}