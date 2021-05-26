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

void display(Node* root) {
    if(root == NULL) return;
    if(root->left == NULL) {
        cout << ".";
    } else {
        cout << root->left->val;
    }
    cout << " -> " << root->val << " <- ";
    if(root->right == NULL) {
        cout << ".";
    } else {
        cout << root->right->val;
    }
    cout << endl;

    display(root->left);
    display(root->right);
}

void recoverBst_(Node* curr, Node*& pre, Node*& f, Node*& s) {
    if(curr == NULL) return;
    recoverBst_(curr->left, pre, f, s);
    if(!f && pre && pre->val > curr->val) {
        f = pre;
        s = curr;
    } else if(f && s->val > curr->val) {
        s = curr;
    }
    pre = curr;
    recoverBst_(curr->right, pre, f, s);
}

void recoverBst(Node* root) {
    Node* f = NULL;
    Node* s = NULL;
    Node* pre = NULL;
    recoverBst_(root, pre, f, s);
    swap(f->val, s->val);
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
    recoverBst(root);
    display(root);
    return 0;
}