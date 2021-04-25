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

void printAllPaths(vector<Edge> *graph, int v, int src, int des, bool *visited, string psf) {
    if(src == des) {
        cout << psf << endl;
    }
    visited[src] = true;
    for(auto e : graph[src]) {
        if(!visited[e.des]) {
            printAllPaths(graph, v, e.des, des, visited,
                psf + (char)(e.des + '0'));
        }
    }
    visited[src] = false;
}

// 6 5
// 1 3 10
// 1 5 32
// 2 3 1
// 3 4 8
// 4 5 10
int main() {
    int n, v;
    cin >> v >> n;
    vector<Edge> graph[v];
    bool visited[v] = {0};
    for(int i = 0; i < n; i++) {
        int src, des , wt;
        cin >> src >> des >> wt;
        graph[src].push_back(Edge(src, des, wt));
        graph[des].push_back(Edge(des, src, wt));
    }
    printAllPaths(graph, v, 1, 5, visited, "1");
    return 0;
}

