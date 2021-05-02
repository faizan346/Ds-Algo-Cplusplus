#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;
    Edge(int s, int d) {
        src = s;
        nbr = d;
    }
};

int main() {
    int v, n;
    cin >> v >> n;
    vector<Edge> graph[v];
    for(int i = 0; i < n; i++) {
        int src, nbr;
        cin >> src >> nbr;
        graph[src].push_back(Edge(src, nbr));
        graph[nbr].push_back(Edge(nbr, src));
    }
    bool visited[v];
    memset(visited, 0, sizeof(visited));
    //breadth first traversal;
    int src;
    cin >> src;
    cout << "bfs : ";
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if(visited[v]) {
            continue;
        }
        visited[v] = true;
        cout << v << " ";
        for(auto e : graph[v]) {
            if(!visited[e.nbr]) {
                q.push(e.nbr);
            }
        }
    }
    cout << endl;

    return 0;
}
// 7
// 8
// 0 1
// 0 3
// 3 2
// 1 2
// 1 4
// 4 5
// 4 6
// 5 6
// 2