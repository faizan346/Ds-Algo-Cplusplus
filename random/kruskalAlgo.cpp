#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int u;
    int v;
    int wt;
    Edge(int src, int des, int weight) {
        u = src;
        v = des;
        wt = weight;
    }
};
//edge list representation
class Graph {
    public:
    int numberOfVertices;
    int numberOfEdges;
    vector<Edge> edges;
    Graph(int V) {
        numberOfVertices = V;
        numberOfEdges = 0;
    }
    void addEdge(Edge e) {
        edges.push_back(e);
        numberOfEdges++;
    }
    void removeEdge(Edge e) {
        for(int i = 0; i < edges.size(); i++) {
            if(e.u == edges[i].u && e.v == edges[i].v) {
                edges.erase(edges.begin() + i);
                numberOfEdges--;
                return;
            }
        }
    }
    void showEdges() {
        cout << endl;
        for(auto e : edges) {
            cout << e.u << " " << e.v << " " << e.wt << endl;
        }
    }
};

void heapify(vector<Edge> &a, int n, int i) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int smallestInd = i;
    if(leftChild < n && a[leftChild].wt < a[smallestInd].wt) {
        smallestInd = leftChild;
    } 
    if(rightChild < n && a[rightChild].wt < a[smallestInd].wt) {
        smallestInd = rightChild;
    } 
    if(smallestInd != i) {
        swap(a[i],a[smallestInd]);
        heapify(a,n,smallestInd);
    }
}

void minHeap(vector<Edge> &edges) {
    int n = edges.size();
    for(int i = n/2 -1 ; i > -1 ; i--) {
        heapify(edges, n, i);
    }
}

void Union(int p1, int p2, int *subset) {
    subset[p1] = p2;
}
//dft
int find(int v, int *subset) {
    if(subset[v] == -1) return v;
    return find(subset[v], subset);
}

void kruskalAlgo(Graph g) {
    int vertices = g.numberOfVertices;
    int totalEdges = g.numberOfEdges;
    Graph minSpanTree(vertices);
    minHeap(g.edges);
    //g.showEdges();
    int subset[vertices];
    memset(subset,-1,sizeof(subset));
    for(int i = totalEdges-1; i > -1; i--) {
        Edge minEdge = g.edges[0];
        g.edges[0] = g.edges[i];
        heapify(g.edges, i, 0);

        int p1 = find(minEdge.u,subset);
        int p2 = find(minEdge.v,subset);
        if(p1 != p2) {
            minSpanTree.addEdge(minEdge);
            Union(p1,p2,subset);
        }
        if(minSpanTree.numberOfEdges >= vertices - 1) break;
    }
    minSpanTree.showEdges();
}

int main() {
    Graph g(9);
    g.addEdge(Edge(1 ,0,4));
    g.addEdge(Edge(7 ,0,8));
    g.addEdge(Edge(1 ,7,11));
    g.addEdge(Edge(1 ,2,8));
    g.addEdge(Edge(7 ,8,7));
    g.addEdge(Edge(7 ,6,1));
    g.addEdge(Edge(2 ,8,2));
    g.addEdge(Edge(6 ,8,6));
    g.addEdge(Edge(2 ,5,4));
    g.addEdge(Edge(2 ,3,7));
    g.addEdge(Edge(6 ,5,2));
    g.addEdge(Edge(3 ,5,14));
    g.addEdge(Edge(3 ,4,9));
    g.addEdge(Edge(5 ,4,10));
    g.showEdges();

    kruskalAlgo(g);

    return 0;
}