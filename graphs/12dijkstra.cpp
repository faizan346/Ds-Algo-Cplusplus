#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int nbr;
    int wt;
    Edge(int s, int d, int w = 0) {
        src = s;
        nbr = d;
        wt  = w;
    }
};

class Pair {
    public:
    int src;
    string psf;
    int wsf;
    Pair(int s, string p, int w) {
        src = s;
        psf = p;
        wsf = w;
    }
};

struct CompareWeightSofar {
    bool operator()(Pair const& p1, Pair const& p2)
    {
        return p1.wsf > p2.wsf;
    }
};

void dijkstra(vector<Edge> *graph, int src, bool *visited) {
    string psf = "";
    psf = (char)(src + '0');
    priority_queue<Pair, vector<Pair>, CompareWeightSofar> pq;
    pq.push(Pair(src, psf, 0));
    while(!pq.empty()) {
        Pair p = pq.top();
        pq.pop();
        if(visited[p.src]) {
            continue;
        }
        visited[p.src] = true;
        cout << p.src << "via" << p.psf <<"@" << p.wsf << endl;  
        for(auto e : graph[p.src]) {
            if(!visited[e.nbr]) {
                pq.push(Pair(e.nbr, p.psf + (char)(e.nbr + '0'), p.wsf + e.wt));
            }
        }
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    vector<Edge> graph[v];
    for(int i = 0; i < n; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(src, nbr, wt));
        graph[nbr].push_back(Edge(nbr, src, wt));
    }
    bool visited[v];
    memset(visited, 0, sizeof(visited));
    int src;
    cin >> src;
    dijkstra(graph, src, visited);

    return 0;
}

// 7
// 8
// 0 1 10
// 0 3 40
// 1 2 10
// 3 2 10
// 3 4 2
// 4 5 3
// 4 6 8
// 5 6 3
// 0