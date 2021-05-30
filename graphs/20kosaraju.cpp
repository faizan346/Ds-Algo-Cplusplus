#include<bits/stdc++.h>
using namespace std;
// find random dfs order, 
// make new reverse graph,
// at last dfs through reverse graph according
// to random order stored in stack.
// we did this becoz when we have strongly connected component which has 
// has edge directing to other strongly connected component then we have to
// find the order in which the other strongly component which dont have edge
// to other strongly component runs first so what we did we just change the 
// state of strongly component by reversing the graph. so know if we 
// go according the order stored in stack from prev dfs it will actually 
// cover those strongly ConComp first which do not have edges to other
// strongly connected component.
class Edge {
    public:
    int src;
    int nbr;
    Edge(int src, int des) {
        this->src = src;
        this->nbr = des;
    }
};

void dfs(vector<vector<Edge>>& graph, int src, stack<int>& st, vector<bool>& visited) {
    visited[src] = true;
    for(auto e : graph[src]){
        if(visited[e.nbr]) continue;
        dfs(graph, e.nbr, st, visited);
    }
    st.push(src);
}

void transpose(vector<vector<Edge>>& graph, vector<vector<Edge>>& newGraph) {
    for(auto ver : graph) {
        for(auto e : ver) {
            newGraph[e.nbr].push_back(Edge(e.nbr, e.src));
        }
    }
}

void dfs(vector<vector<Edge>>& graph, int src, vector<bool>& visited) {
    visited[src] = true;
    for(auto e : graph[src]){
        if(visited[e.nbr]) continue;
        dfs(graph, e.nbr, visited);
    }
}

void kosaraju(vector<vector<Edge>>& graph) {
    int v = graph.size();
    stack<int> st;
    vector<bool> visited(v, false);
    for(int src = 0; src < v; src++) {
        if(visited[src]) continue;
        dfs(graph, src, st, visited);
    }
    vector<vector<Edge>> newGraph(v, vector<Edge>());
    transpose(graph, newGraph);
    visited = vector<bool>(v, false);
    int comp = 0;
    while(!st.empty()) {
        int src = st.top();
        st.pop();
        if(visited[src]) continue;
        dfs(newGraph, src, visited);
        comp++;
    }
    cout << comp << endl;
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

    kosaraju(graph);

    return 0;
}