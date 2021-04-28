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
    int level;
    Pair(int s, string p, int l) {
        src = s;
        psf = p;
        level = l;
    }
};

bool checkCompBipartite(vector<Edge> *graph, int src, int *visited) {
    string psf = "";
    psf = (char)(src + '0');
    queue<Pair> q;
    q.push(Pair(src, psf,0));
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        if(visited[p.src] != -1) {
            if(visited[p.src] != p.level) //odd cycle indictaion
                return false;
            continue;
        }
        visited[p.src] = p.level;
        cout << p.src << "@" << p.psf << endl;  
        for(auto e : graph[p.src]) {
            if(visited[e.des] == -1) {
                q.push(Pair(e.des, p.psf + (char)(e.des + '0'), p.level+1));
            }
        }
    }
    return true;
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
    int visited[v];
    memset(visited, -1, sizeof(visited));
    
    bool bipartite = false;
    for(int i = 0; i < v; i++) {
        if(visited[i] == -1) {
            bipartite = checkCompBipartite(graph, i, visited);
            if(!bipartite) {
                break;
            }
        }
    }
    cout << (bipartite ? "true" : "false") << endl;

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