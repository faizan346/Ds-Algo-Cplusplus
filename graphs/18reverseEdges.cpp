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

int dfs(vector<Edge>* graph, int src, int des, vector<bool>& visited, vector<int>& t) {
    if(src == des) {
        return 0;
    }
    if(t[src] != -1) return t[src];
    visited[src] = true;
    int minRev = 1e8;
    for(auto e : graph[src]) {
        if(!visited[e.nbr]){
            int res = dfs(graph, e.nbr, des, visited, t) + e.wt;
            minRev = min(res, minRev);
        }
    }
    visited[src] = false;
    return t[src] = minRev;
}

class Pair {
    public:
    int src;
    int pwsf;
    Pair(int s, int p) {
        src = s;
        pwsf = p;
    }
};

class Compare {
    public:
    bool operator()(Pair const& a, Pair const& b) {
        return a.pwsf > b.pwsf;
    }
};


int reverseEdges(vector<Edge>* graph, int src, int des, vector<bool>& visited) {
    priority_queue<Pair, vector<Pair>, Compare> pq;
    pq.push(Pair(src, 0));
    while(!pq.empty()) {
        Pair p = pq.top();
        pq.pop();
        if(p.src == des) {
            return p.pwsf;
        }
        visited[p.src] = true;
        for(auto e : graph[p.src]) {
            if(visited[e.nbr]) continue;
            pq.push(Pair(e.nbr, p.pwsf + e.wt));
        }
    }
    return -1;
}


int main() {
    int v, m;
    cin >> v >> m;
    vector<Edge> graph[v];
    for(int i = 0; i < m; i++) {
        int src, nbr;
        cin >> src >> nbr;
        src--; nbr--;
        graph[src].push_back(Edge(src, nbr, 0));
        graph[nbr].push_back(Edge(nbr, src, 1));
    }
    vector<bool> visited(v, false);
    // vector<int> t(v, -1);
    // int ans = dfs(graph, 0, v-1, visited, t);
    // cout << ((ans >= 1e8) ? -1 : ans) << endl;
    cout << reverseEdges(graph, 0, v-1, visited) << endl;
    return 0;
}