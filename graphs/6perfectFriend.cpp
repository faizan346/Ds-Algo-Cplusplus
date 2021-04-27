#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int des;
    int wt;
    Edge(int s, int d, int w = 0) {
        src = s;
        des = d;
        wt = w;
    }
};

void storeComponent(vector<Edge> *graph, int src, vector<int> &comp, bool *visited) {
    visited[src] = true;
    comp.push_back(src);
    for(auto e : graph[src]) {
        if(!visited[e.des]) {
            storeComponent(graph, e.des, comp, visited);
        }
    }
}

int main() {
    int n, v;
    cin >> v >> n;
    vector<Edge> graph[v];
    bool visited[v];
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        int src, des;
        cin >> src >> des;
        graph[src].push_back(Edge(src, des));
        graph[des].push_back(Edge(des, src));
    }
    vector<vector<int>> components;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {           
            vector<int> comp;
            storeComponent(graph, i, comp, visited);
            components.push_back(comp);
        }
    }
    int pair = 0;
    for(int i = 0; i < components.size(); i++) {
        for(int j = i + 1; j < components.size(); j++) {
            int count = components[i].size() * components[j].size();
            pair += count;
        }
    }
    cout << pair << endl;
    return 0;
}

// 7 
// 5
// 0 1 
// 3 2 
// 4 5 
// 5 6 
// 4 6 