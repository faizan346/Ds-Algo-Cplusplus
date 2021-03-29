#include <bits/stdc++.h>
using namespace std;

class Graph {
    int numberOfNodes;
    unordered_map<int, vector<int>> umap;
    public:
    Graph() {
        numberOfNodes = 0;
    }

    void addVertex(int vertex) {
        vector<int> v;
        umap[vertex] = v;
        numberOfNodes++;
    }

    void addEdge(int a , int b) {
        if(umap.find(a) != umap.end() && umap.find(b) != umap.end()) {
            umap[a].push_back(b);
            umap[b].push_back(a);
           
        } else cout << "\ngiven vertex is not present";
    }

    void showConnections() {
        for(auto p : umap) {
            cout << p.first << "-->";
            for(auto n : p.second ) {
                cout << n << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.showConnections();
    
    return 0;
}