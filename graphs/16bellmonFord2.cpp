#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;
    Edge(int src, int des, int wt) {
        this->src = src;
        this->nbr = des;
        this->wt = wt;
    }
};

void shortestPathBellmonFord(vector<Edge>& graph, int v, int src) {
    vector<int> path(v, INT_MAX);   
    path[src] = 0;
    for(int i = 1; i < path.size(); i++) {
        for(auto e : graph) {
            if(path[e.src] == INT_MAX) continue; // still not visited
            if(path[e.src] + e.wt < path[e.nbr]) {
                path[e.nbr] = path[e.src] + e.wt;
            }
        }
    }
    for(int i = 0; i < path.size(); i++) {
        cout << i << "   " << path[i] << endl;
    }
    cout << endl;
}

int main() {
    int v, m;
    cin >> v >> m;
    vector<Edge> graph; // shouldn't have negative cycle
    for(int i = 0; i < m; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph.push_back(Edge(src, nbr, wt));
    }
    int src;
    cin >> src;
    shortestPathBellmonFord(graph, v, src);
    return 0;
}

// 6 5
// 1 2 5
// 1 3 2
// 3 4 1
// 1 4 6
// 3 5 5
// 1