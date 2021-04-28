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
        wt  = w;
    }
};

class Pair {
    public:
    int src;
    string psf;
    Pair(int s, string p) {
        src = s;
        psf = p;
    }
};

bool hasCycle(vector<Edge> *graph, int src, bool *visited) {
    string psf = "";
    psf = (char)(src + '0');
    queue<Pair> q;
    q.push(Pair(src, psf));
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        if(visited[p.src]) {
            return true;
        }
        visited[p.src] = true;
        cout << p.src << "@" << p.psf << endl;  
        for(auto e : graph[p.src]) {
            if(!visited[e.des]) {
                q.push(Pair(e.des, p.psf + (char)(e.des + '0')));
            }
        }
    }
    return false;
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<Edge> graph[v];
    for(int i = 0; i < n; i++) {
        int src, des;
        cin >> src >> des;
        graph[src].push_back(Edge(src, des));
        graph[des].push_back(Edge(des, src));
    }
    bool visited[v];
    memset(visited, 0, sizeof(visited));
    
    bool cycle = false;
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            cycle = hasCycle(graph, i, visited);
            if(cycle) {
                break;
            }
        }
    }
    cout << (cycle ? "true" : "false") << endl;

    return 0;
}

// 7
// 4
// 0 1
// 2 3
// 4 5
// 5 6
//fasle
// 7
// 5
// 0 1
// 2 3
// 4 5
// 5 6
// 4 6
//true;