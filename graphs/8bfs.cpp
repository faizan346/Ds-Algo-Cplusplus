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
    //breadth first traversal;
    int src;
    cin >> src;
    string psf = "";
    psf = (char)(src + '0');
    queue<Pair> q;
    q.push(Pair(src, psf));
    //visited[src] = true;
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        ////
        //by writing visit here we can actually know that we can come here from
        //different path but if i put this in these statement in below comment
        //it would have come here because even before exploring the real thing 
        //it would be marked and can be push into queue through other nodes
        if(visited[p.src]) {
            continue;
        }
        visited[p.src] = true;
        ///
        cout << p.src << "@" << p.psf << endl;
        for(auto e : graph[p.src]) {
            if(!visited[e.des]) {
                //visited[e.des] = true;
                q.push(Pair(e.des, p.psf + (char)(e.des + '0')));
            }
        }
    }

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