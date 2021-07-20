#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int u;
    int v;
    int wt;
    Edge(int u, int v, int wt) {
        this->u = u, this->v = v, this->wt = wt;
    }
};

class Pair{
    public:
    int u;
    int par;
    int psf;
    Pair(int u, int par, int psf) {
        this->u = u, this->par = par, this->psf = psf;
    }
};

struct Compare {
    bool operator()(Pair const& p1, Pair const& p2) {
        return p1.psf > p2.psf;
    }
};

vector<int> dikjstra(vector<vector<Edge>> &graph, int src, int des, vector<bool> &visited) {
    int n = graph.size();
    vector<int> par(n, -1);
    priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push(Pair(src, -1, 0));
    while(!pq.empty()) {
        Pair p = pq.top();
        pq.pop();
        if(visited[p.u]) continue;
        visited[p.u] = true;
        par[p.u] = p.par;
        for(auto e : graph[p.u]) {
            if(!visited[e.v]) {
                pq.push(Pair(e.v, e.u, p.psf + e.wt));
            }
        }
    }
    vector<int> ntv;
    int u = par[des];
    while(u != src) {
        ntv.push_back(u);
        u = par[u];
    }
    return ntv;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n, vector<Edge>());
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back(Edge(u, v, wt));
        graph[v].push_back(Edge(v, u, wt));
    }
    int src, des;
    cin >> src >> des;
    vector<bool> visited(n, false);
    vector<int> ntv = dikjstra(graph, src, des, visited);
    visited = vector<bool>(n, false);
    for(auto x : ntv) {
        visited[x] = true;
    }
    vector<int> ans = dikjstra(graph, des, src, visited);
    cout << src << " ";
    for(auto x : ans) cout << x << " ";
    cout << des << endl;
}