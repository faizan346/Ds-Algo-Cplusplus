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
//just replace queue with stack in bfs to get dfs
//why we do it because main stack has limited value to make functional frame
//for recursive calls and it can make stack to overflow
//if graph is bigger it is advised to use this iteration method
//and make stack object rather than stack frame in heap memory for better.
void dfsIterate(vector<Edge> *graph, int src, bool *visited) {
    string psf = "";
    psf = (char)(src + '0');
    stack<Pair> *s = new stack<Pair>();
    s->push(Pair(src, psf));
    while(!s->empty()) {
        Pair p = s->top();
        s->pop();
        if(visited[p.src]) {
            continue;
        }
        visited[p.src] = true;
        cout << p.src << "@" << p.psf << endl;  
        for(auto e : graph[p.src]) {
            if(!visited[e.des]) {
                s->push(Pair(e.des, p.psf + (char)(e.des + '0')));
            }
        }
    }
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
    int src;
    cin >> src;
    dfsIterate(graph, src, visited);

    return 0;
}
// 7
// 8
// 0 1
// 0 3
// 1 2
// 2 3
// 4 3
// 4 5
// 4 6
// 5 6
// 0