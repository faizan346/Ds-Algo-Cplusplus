#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    Edge(int src, int des) {
        this->src = src;
        this->nbr = des;
    }
};

void courseScheule(vector<vector<Edge>>& graph) {
    vector<int> indegree(graph.size(), 0);
    for(auto ver : graph) {
        for(auto e : ver) {
            indegree[e.nbr]++;
        }
    }
    queue<int> q;
    for(int v = 0; v < indegree.size(); v++) {
        if(indegree[v] == 0) q.push(v);
    }
    int count = 0;
    vector<int> ans;
    while(!q.empty()) {
        int ver = q.front();
        q.pop();
        count++;
        ans.push_back(ver);
        for(auto e : graph[ver]) {
            if(--indegree[e.nbr] == 0) q.push(e.nbr);
        }
    }
    if(count == graph.size()) {
        for(auto it = ans.rbegin(); it != ans.rend(); it++) {
            cout << *it << " ";
        }
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    int v, m;
    cin >> v >> m;
    vector<vector<Edge>> graph(v, vector<Edge>());
    for(int i = 0; i < m; i++) {
        int src, nbr;
        cin >> src >> nbr;
        graph[src].push_back(Edge(src, nbr));
    }

    courseScheule(graph);
    return 0;
}