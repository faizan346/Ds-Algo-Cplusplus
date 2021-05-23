//for all purmutation of vertices such the 
//for all the edges uv, u should appear first
//graph should not contain any cycle becoz no
//two vertices or task can be dependent on each other
#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int u;
    int v;
    Edge(int u, int v) {
        this->u = u;
        this->v = v;
    }
};
//it helps to tell the priority/order of the task to be done but
//sometimes we can't reach every node in one cycle that means we have no means
//to know which cycle should occur first so their could be multitple answer for that 
//depending which  cycle you are iterating first

void topoligicalSort(vector<Edge> *graph, int src, bool* visited, stack<int> &s) {
    visited[src] = true;
    for(auto e: graph[src]) {
        if(!visited[e.v]) {
            topoligicalSort(graph, e.v, visited, s);
        }
    }
    s.push(src);
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<Edge> graph[v];
    for(int i = 0; i < n; i ++) {
        int src, nbr;
        cin >> src >> nbr;
        graph[src].push_back(Edge(src, nbr));
    }
    bool visited[v];
    memset(visited, 0, sizeof(visited));
    stack<int> s;
    for(int i = 0; i < v; i++) {
        if(!visited[i])
            topoligicalSort(graph, i, visited, s);
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
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