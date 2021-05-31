#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;
    Edge(int s, int d, int w = 0) {
        src = s;
        nbr = d;
        wt  = w;
    }
};

class PairEdge {
    public:
    int src;
    int parent;
    int wt;
    PairEdge(int s, int p, int w) {
        src = s;
        parent = p;
        wt = w;
    }
};

struct CompareWeightEdge {
    bool operator()(PairEdge const& p1, PairEdge const& p2) {
        return p1.wt > p2.wt;
    }
};
//it will give the minumum cost to connect all nodes with given edges
void prims(vector<Edge> *graph, int src, bool *visited) {
    priority_queue<PairEdge, vector<PairEdge>, CompareWeightEdge> pq;
    pq.push(PairEdge(src, -1, 0));
    while(!pq.empty()) {
        PairEdge p = pq.top();
        pq.pop();
        if(visited[p.src]) {
            continue;
        }
        visited[p.src] = true;
        if(p.parent != -1) {
            cout << p.parent << " --- " << p.src <<"  @" << p.wt << endl;
        }
        for(auto e : graph[p.src]) {
            if(!visited[e.nbr]) {
                pq.push(PairEdge(e.nbr, p.src, e.wt));
            }
        }
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<Edge> graph[v];
    for(int i = 0; i < n; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(src, nbr, wt));
        graph[nbr].push_back(Edge(nbr, src, wt));
    }
    bool visited[v];
    memset(visited, 0, sizeof(visited));
    int src;
    cin >> src;
    prims(graph, src, visited);

    return 0;
}

// 7
// 8
// 0 1 10
// 0 3 40
// 1 2 10
// 3 2 10
// 3 4 2
// 4 5 3
// 4 6 8
// 5 6 3
// 0