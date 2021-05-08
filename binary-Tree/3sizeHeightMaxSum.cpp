#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Pair {
    public:
    Node* node;
    int child;
    Pair(Node* n, int i) {
        node = n;
        child = i;
    }
};

void display(Node* root) {
    if(root == NULL) return;
    
    if(root->left !=NULL) {
        cout << root->left->data;
    } else {
        cout << ".";
    }
    cout << "<-" << root->data<< "->";
    if(root->right != NULL) {
        cout <<root->right->data;
    } else {
        cout << ".";
    }
    cout << endl;

    display(root->left);
    display(root->right);
}

void sizeHeightMaxSum(Node* root, int depth, int& size, int& height, int& max, int& sum) {
    if(root == NULL) return;
    size++;
    if(root->data > max) max = root->data;
    if(depth > height) height = depth;
    sum += root->data;
    sizeHeightMaxSum(root->left, depth + 1, size, height, max, sum);
    sizeHeightMaxSum(root->right, depth + 1, size, height, max, sum);
}

int main() {
    int a[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int n = sizeof(a)/sizeof(a[0]);

    stack<Pair> st;
    Node* root;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            Pair &p = st.top();
            if(p.child == 0) {
                p.node->left = NULL;
                p.child++;
            } else if(p.child == 1){
                p.node->right = NULL;
                p.child++;
                st.pop();
            }
        } else {
            Node* node = new Node(a[i]);
            if(st.empty()) {
                root = node;
            } else {
                Pair &p = st.top();
                if(p.child == 0) {
                    p.node->left = node;
                    p.child++;
                } else if(p.child == 1){
                    p.node->right = node;
                    p.child++;
                    st.pop();
                }
            }
            st.push(Pair(node, 0));
        }
    }
    int max = INT_MIN;
    int sum = 0;
    int size = 0;
    int height = 0;
    sizeHeightMaxSum(root, 0, size, height, max, sum);
    cout << "max = " << max << endl;
    cout << "sum = " << sum << endl;
    cout << "size = " << size << endl;
    cout << "height = " << height << endl;
    return 0;
}