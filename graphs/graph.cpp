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

class Graph {
    public:
    vector<Edge> *v;
    int ver;
    Graph(int vertices = 100) {
        v = new vector<Edge>[vertices];
        ver = vertices;
    }
    void addEdge(Edge e) {
        v[e.src].push_back(e);
    }
    void display() {
        for(int i = 0; i < ver; i++) {
            cout << i << " : ";
            for(auto e : v[i]) {
                cout << e.src << " " << e.des << " " << e.wt << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, v;
    cin >> v >> n;
    Graph g(v);
    for(int i = 0; i < n; i++) {
        int src, des , wt;
        cin >> src >> des >> wt;
        g.addEdge(Edge(src, des, wt));
        g.addEdge(Edge(des, src, wt));
    }
    g.display();
    return 0;
}

// 6 5
// 1 3 10
// 1 5 32
// 2 3 1
// 3 4 8
// 4 5 10