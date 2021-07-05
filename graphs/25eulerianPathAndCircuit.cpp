#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int nbr;
    int wt;
    Edge(int n, int w) {
        nbr = n, wt = w;
    }
};

// undirected
void eulerianPathAndCircuit1(unordered_map<int, vector<Edge>>& graph, int src) {
    int n = graph.size();
    vector<int> degree(n, 0);
    for(auto x : graph) {
        int v = x.first;
        degree[v] = x.second.size();
    }
    int countOdd = 0;
    for(auto x : degree) {
        if((x & 1) == 1) countOdd++; 
    }
    if(countOdd == 0) {
        cout << "eulerianCircuit" << endl;
    } else if(countOdd == 2 && (graph[src].size() & 1) == 1) {
        cout << "eulerianPath" << endl;
    } else {
        cout << "neither" << endl;
    }
}
// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8


// directed
void eulerianPathAndCircuit2(unordered_map<int, vector<Edge>>& graph, int src, int n) {
    vector<int> inDegree(n, 0);
    vector<int> outDegree(n, 0);
    for(auto x : graph) {
        int v = x.first;
        outDegree[v] = x.second.size();
        for(auto e : x.second) {
            inDegree[e.nbr]++;
        }
    }
    int notMatch = 0;
    int des;
    for(int v = 0; v < n; v++) {
        if(inDegree[v] != outDegree[v]) notMatch++; 
        if(notMatch != 0 && v != src) des = v; 
    }
    if(notMatch == 0) {
        cout << "eulerianCircuit" << endl;
    } else if(notMatch == 2 && outDegree[src] == (inDegree[src] + 1) 
            && inDegree[des] == (outDegree[des] + 1)) {
        cout << "eulerianPath" << endl;
    } else {
        cout << "neither" << endl;
    }
}
// 4
// 3
// 0 1 10
// 1 2 10
// 2 3 10
// 0

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0; i < m; i++) {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(nbr, wt));
        //graph[nbr].push_back(Edge(src, wt));
    }
    
    int src;
    cin >> src;
    //eulerianPathAndCircuit1(graph, src);
    eulerianPathAndCircuit2(graph, src, n);
    return 0;
}

// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8