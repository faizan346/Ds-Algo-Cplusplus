#include<bits/stdc++.h>
using namespace std;

class Pair {
    public:
    int v;
    int level;
    Pair(int v, int level) {
        this->v = v;
        this->level = level;
    }
};
class Edge {
    public:
    int src;
    int des;
    int wt;
    Edge(int s, int d) {
        src = s;
        des = d;
    }
};

void virusSpread(vector<Edge> *graph, vector<int> &visited, int t) {
    int v;
    cin >> v;
    queue<Pair> q;
    q.push(Pair(v,1));
    int count = 0;
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        if(visited[p.v] > 0) {
            continue;
        }
        visited[p.v] = p.level;
        if(p.level > t) { //if infection time reaches greater than given time than don't include it 
            break;
        }
        count++;
        for(auto e : graph[p.v]) {
            if(visited[e.des] == 0) {
                q.push(Pair(e.des, p.level+1));
            }
        }

    }
    cout << count << endl;
}

int main() {
    int n, v;
    cin >> v >> n;
    vector<Edge> graph[v];
    for(int i = 0; i < n; i ++) {
        int des, src;
        cin >> des >> src;
        graph[src].push_back(Edge(src, des));
        graph[des].push_back(Edge(des, src));
    }
    vector<int> visited(v, 0);
    int t;
    cin >> t;
    virusSpread(graph, visited, t);
    return 0;
}

// 7
// 8
// 0 1
// 0 3
// 1 2
// 3 2
// 3 4
// 4 5
// 4 6
// 5 6
// 6
// 4