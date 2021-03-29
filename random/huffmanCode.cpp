#include<bits/stdc++.h>
using namespace std;

class NodeMinHeap {
    public:
    NodeMinHeap* left;
    NodeMinHeap* right;
    int freq;
    char data;
    NodeMinHeap(int f, char d) {
        left = NULL;
        right = NULL;
        freq = f;
        data = d;
    }
};

struct Compare {
    public:
    bool operator()(NodeMinHeap* l, NodeMinHeap* r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(NodeMinHeap* top, string print) {
    if(!top) return;

    if(top->data != '$') {
        cout << top->data << " : " << print << endl;
        return;
    }
    printCodes(top->right, print + "1");
    printCodes(top->left, print + "0");
}


void huffmanCodes(char *a, int *f, int n) {
    priority_queue<NodeMinHeap*, vector<NodeMinHeap*>, Compare> minHeap;
    for(int i = 0 ; i < n; i++) {
        NodeMinHeap *node = new NodeMinHeap(f[i], a[i]);
        minHeap.push(node);
    }

    NodeMinHeap *left,*right, *top;
    while(minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        
        top = new NodeMinHeap(left->freq + right->freq, '$');
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    huffmanCodes(arr, freq, size);
    return 0;
}