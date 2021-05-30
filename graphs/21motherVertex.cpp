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

void dfs(vector<vector<Edge>>& graph, int src,stack<int>& st, vector<bool>& visited) {
    visited[src] = true;
    for(auto e : graph[src]){
        if(visited[e.nbr]) continue;
        dfs(graph, e.nbr, st, visited);
    }
    st.push(src);
}

void dfs(vector<vector<Edge>>& graph, int src, int& count, vector<bool>& visited) {
    visited[src] = true;
    count++;
    for(auto e : graph[src]){
        if(visited[e.nbr]) continue;
        dfs(graph, e.nbr, count, visited);
    }
}

void motherVertex(vector<vector<Edge>>& graph) {
    int v = graph.size();
    vector<bool> visited(v, false);
    stack<int> st;
    for(int src = 0; src < v; src++) {
        if(visited[src]) continue;
        dfs(graph, src, st, visited);
    }
    int count = 0;
    int mv = st.top();
    visited = vector<bool>(v, false);
    dfs(graph, mv, count, visited);
    if(count == v) {
        cout << mv + 1;
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
        graph[src-1].push_back(Edge(src-1, nbr-1));
    }

    motherVertex(graph);

    return 0;
}