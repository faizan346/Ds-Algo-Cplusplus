#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int des;
    int wt;
    Edge(int s, int d, int w) {
        src = s;
        des = d;
        wt = w;
    }
};

void displayGraph(vector<Edge> *graph, int v) {
    for(int i =0 ; i < v; i++) {
        cout << i << " : ";
        for(auto e : graph[i]) {
            cout << e.src << " " << e.des << " " << e.wt << " | ";
        }
        cout << endl;
    }
}

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
        int src, des , wt;
        cin >> src >> des >> wt;
        graph[src].push_back(Edge(src, des, wt));
        graph[des].push_back(Edge(des, src, wt));
    }
    vector<vector<int>> components;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {           
            vector<int> comp;
            storeComponent(graph, i, comp, visited);
            components.push_back(comp);
        }
    }
    for(auto c : components) {
        for(auto x : c) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

// 7 5
// 0 1 0
// 3 2 0
// 4 5 0
// 5 6 0
// 4 6 0