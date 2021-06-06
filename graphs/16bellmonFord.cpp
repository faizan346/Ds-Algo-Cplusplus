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

void shortestPathBellmonFord(vector<Edge>& graph, vector<int>& path) {
    // the path to ith dist vertext could take <= i iteration to get set
    for(int i = 1; i < path.size(); i++) { // iterating edges again and again as we have to set the vertex u befroe vertex v in path
        for(auto e : graph) {
            if(path[e.src] == INT_MAX) continue;
            // check for two things first to check whether cur path wt  
            // upto curr ver is greater than prev path wt and second whether 
            // the path to prev vertex is set or not..
            if(path[e.src] + e.wt < path[e.nbr]) {
                path[e.nbr] = path[e.src] + e.wt;
            }
        }
    }
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
    vector<int> path(v, INT_MAX);   
    path[1] = 0;
    shortestPathBellmonFord(graph, path);
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}

// 6 5
// 1 2 5
// 1 3 2
// 3 4 1
// 1 4 6
// 3 5 5