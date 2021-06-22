#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;
    Edge(int s, int n, int w) {
        src = s, nbr = n, wt = w;
    }
};

struct CompareWt {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
        return p1.second > p2.second;
    }
};

void solve(unordered_map<int, vector<Edge>>& graph) {
    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareWt> pq;
    int cost = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int src = p.first;
        int wt = p.second; // edge wt from parent to src vertex;
        if(visited.count(src)) continue;
        visited.insert(src);
        cost += wt;
        for(auto e : graph[src]) {
            if(!visited.count(e.nbr)) {
                pq.push({e.nbr, e.wt});
            }
        }
    }
    cout << cost << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0; i < m; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(src, nbr, wt));
        graph[nbr].push_back(Edge(nbr, src, wt));
    }
    
    solve(graph);
    return 0;
}

// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8
// 38