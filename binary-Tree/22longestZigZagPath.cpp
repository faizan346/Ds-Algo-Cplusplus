#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int val) {
        this->val = val;
    }
};

Node* createTree1(vector<int> &arr, int& ind) {
    if (ind > arr.size() || arr[ind] == -1) {
        ind++;
        return nullptr;
    }
    Node *node = new Node(arr[ind++]);
    node->left = createTree1(arr, ind);
    node->right = createTree1(arr, ind);

    return node;
}

class Pair {
    public:
    int lp = -1;
    int rp = -1;
    int max = 0;
};

Pair longestZigZagBT_(Node* root) {
    if(root == NULL) return Pair();
    Pair l = longestZigZagBT_(root->left);
    Pair r = longestZigZagBT_(root->right);
    Pair mres;
    mres.lp = l.rp + 1;
    mres.rp = r.lp + 1;
    mres.max = max(max(l.max, r.max), max(mres.lp, mres.rp));
    return mres;
}

int longestZigZagBT(Node* root) {
    Pair res = longestZigZagBT_(root);
    return res.max;
}


int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int v; 
        cin >> v;
        a.push_back(v);
    }
    int ind = 0;
    Node* root = createTree1(a, ind);
    cout << longestZigZagBT(root) << endl;
    return 0;
}