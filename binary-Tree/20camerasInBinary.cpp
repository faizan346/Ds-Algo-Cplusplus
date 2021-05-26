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

class PairAns {
    public:
    int res;
    int state;
    PairAns(int res, int state) {
        this->res = res;
        this->state = state;
    }
};
// state = 1 camera is not covering the child
// state = 2 camera is covering the child
// state = 3 child has camera
PairAns minCamerasInBTHelper(Node* root) {
    if(root == NULL) {
        return PairAns(0, 2);
    }
    PairAns l = minCamerasInBTHelper(root->left);
    PairAns r = minCamerasInBTHelper(root->right);
    PairAns curr(l.res + r.res, 1);
    if(l.state == 1 || r.state == 1) {
            curr.state = 3;
            curr.res += 1;
    } else if(l.state == 3 || r.state == 3) {
            curr.state = 2;
    }
    return curr;
}

int minCamerasInBT(Node* root) {
    PairAns c = minCamerasInBTHelper(root);
    if(c.state == 1) c.res++;
    return c.res;
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
    cout << minCamerasInBT(root) << endl;
    return 0;
}