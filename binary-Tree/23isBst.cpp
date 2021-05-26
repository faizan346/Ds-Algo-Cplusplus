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
    int max = INT_MIN;
    int min = INT_MAX;
    bool isBst = true;
};

Pair isBst_(Node* root) {
    if(root == NULL) {
        return Pair();
    }
    Pair l = isBst_(root->left);
    Pair r = isBst_(root->right);
    Pair mres;
    mres.isBst = l.isBst && (l.max < root->val) 
        &&  r.isBst && (r.min > root->val);
    mres.max = max(root->val, max(l.max, r.max));
    mres.min = min(root->val, min(l.min, r.min));
    return mres;
}

void isBst_(Node* cur, Node*& pre, bool& bst) {
    if(bst == false || cur == NULL) return;
    isBst_(cur->left, pre, bst);
    if(pre && pre->val > cur->val) {
        bst = false;
    }
    pre = cur;
    isBst_(cur->right, pre, bst);
}

bool isBst_(Node* curr, Node*& pre) {
    if(curr == NULL) return true;
    if(!isBst_(curr->left, pre)) return false;
    if(pre && pre->val > curr->val) return false;
    pre = curr;
    if(!isBst_(pre->right, pre)) return false;
    return true;
}

bool isBst(Node* root) {
    // Pair res = isBst_(root);
    // return res.isBst;
    
    // bool bst = true;
    Node* pre = NULL;
    // isBst_(root, pre, bst);
    // return bst;

    return isBst_(root, pre);
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
    cout << (isBst(root) ? "true" : "false") << endl;
    return 0;
}