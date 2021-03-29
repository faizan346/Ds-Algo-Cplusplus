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
    } else {
        printCodes(top->right, print + "1");
        printCodes(top->left, print + "0");
    }
}

vector<pair<char, string>> getCodes(NodeMinHeap* top) {
    if(top->data != '$') {
        vector<pair<char, string>> mres;
        pair<char, string> p;
        p.first = top->data;
        p.second = "";
        mres.push_back(p);
        return mres;
    }
    vector<pair<char, string>> resl = getCodes(top->left);
    vector<pair<char, string>> resr = getCodes(top->right);
    vector<pair<char, string>> mres;
    for(auto x : resl) {
        pair<char, string> p;
        p.first = x.first;
        p.second = '0' + x.second;
        mres.push_back(p);
    }
    for(auto x : resr) {
        pair<char, string> p;
        p.first = x.first;
        p.second = '1' + x.second;
        mres.push_back(p);
    }
    return mres;
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

    //printCodes(minHeap.top(), "");
    vector<pair<char, string>> v = getCodes(minHeap.top());
    for(auto p : v) {
        cout << p.first << " : " << p.second << endl;
    }

}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 1, 1, 1, 1, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    huffmanCodes(arr, freq, size);
    return 0;
}