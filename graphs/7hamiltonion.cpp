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

void displayGraph(vector<Edge> *graph, int v) {
    for(int i =0 ; i < v; i++) {
        cout << i << " : ";
        for(auto e : graph[i]) {
            cout << e.src << " " << e.des << " " << e.wt << " | ";
        }
        cout << endl;
    }
}

void hamiltonionPath(vector<Edge> *graph, int v, int src, int osrc, string psf, bool *visited) {
    if(psf.size() == v) {
        bool hamiltonionCycle = false;
        for(auto e : graph[src]) {
            if(e.des == osrc) {
                hamiltonionCycle = true;
            }
        }
        if(hamiltonionCycle == true) {
            cout << psf << "*" << endl;
        } else {
            cout << psf << "." << endl;
        }
    }
    visited[src] = true;
    for(auto e : graph[src]) {
        if(!visited[e.des]) {
            hamiltonionPath(graph, v, e.des, osrc, psf + (char)(e.des + '0'), visited);
        }
    }
    visited[src] = false;
}
// 7
// 9
// 0 1
// 0 3
// 1 2
// 3 2
// 3 4
// 2 5
// 4 5
// 5 6
// 4 6
// 0

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
    int src;
    cin >> src;
    string psf = "";
    psf += (char)(src + '0');
    hamiltonionPath(graph, v, src, src, psf, visited);
    return 0;
}

