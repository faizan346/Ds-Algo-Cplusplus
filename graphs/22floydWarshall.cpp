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

void floydWarshall(vector<vector<Edge>>& graph) {
    int v = graph.size();
    // stores the shortest path between two vertices
    // with different set of intermediatry vertices
    vector<vector<int>> dist(v, vector<int>(v, INT_MAX));
    // when there is no intermediate vertex between the vertices
    for(int i = 0; i < v; i++) {
        for(auto e : graph[i]) {
            dist[e.src][e.nbr] = e.wt;
        }
        dist[i][i] = 0;
    }

    for(int k = 0; k < v; k++) { //intermediates
        for(int i = 0; i < v; i++) { // src vertex
            for(int j = 0; j < v; j++) { // des vertex
                // if intermediate path is unreachable continue to next.
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for(auto y : dist) {
        for(auto x : y) {
            if(x == INT_MAX) cout << "NA";
            else cout << x;
            cout << "    ";
        }
        cout << endl;
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
    floydWarshall(graph);
}