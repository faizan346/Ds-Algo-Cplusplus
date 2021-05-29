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

bool negativeCycle(vector<Edge>& graph, vector<int>& path) {
    for(int i = 0; i < path.size(); i++) { // v iterations
        for(auto e : graph) {
            if(path[e.src] == INT_MAX) continue;
            if(i == path.size()-1) { //vth iteration
                if(path[e.src] + e.wt != path[e.nbr]) {
                    return true;
                }
            } else if(path[e.src] + e.wt < path[e.nbr]) {
                    path[e.nbr] = path[e.src] + e.wt;
            }
        }
    }
    return false;
}

int main() {
    int v, m;
    cin >> v >> m;
    vector<Edge> graph;
    for(int i = 0; i < m; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph.push_back(Edge(src, nbr, wt));
    }
    vector<int> path(v, INT_MAX);
    path[0] = 0;
    cout << negativeCycle(graph, path) << endl;
    return 0;
}