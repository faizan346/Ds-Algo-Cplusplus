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
    int inc;
    int exc;
};

Pair houseRobberHelper(Node* root) {
    if(root == NULL) {
        Pair mres;
        mres.inc = 0;
        mres.exc = 0;
        return mres;
    }
    Pair l = houseRobberHelper(root->left);
    Pair r = houseRobberHelper(root->right);
    Pair mres;
    mres.inc = root->val + l.exc + r.exc;
    mres.exc = max(l.exc, l.inc) + max(r.exc, r.inc);
    return mres;
}
int houseRobber(Node* root) {
    Pair res = houseRobberHelper(root);
    return max(res.exc, res.inc);
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
    cout << houseRobber(root) << endl;
    return 0;
}