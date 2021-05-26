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

Node *createTree1(vector<int> &arr, int& ind) {
    if (ind > arr.size() || arr[ind] == -1) {
        ind++;
        return nullptr;
    }
    Node *node = new Node(arr[ind++]);
    node->left = createTree1(arr, ind);
    node->right = createTree1(arr, ind);

    return node;
}

Node* createTree2(vector<int>& a) {
    if(a.empty()) return NULL;
    stack<Pair> st;
    Node* root = new Node(a[0]);
    st.push(Pair(root, 1));
    int i = 1;
    while(!st.empty()) {
        Pair &p = st.top();
        if(p.child == 1) {
            if(a[i] == -1) {
                p.node->left = NULL;
            } else {
                p.node->left = new Node(a[i]);
                st.push(Pair(p.node->left, 1));
            }
            i++;
            p.child++;
        } else if(p.child == 2) {
            if(a[i] == -1) {
                p.node->right = NULL;
            } else {
                p.node->right = new Node(a[i]);
                st.push(Pair(p.node->right, 1));
            }
            i++;
            p.child++;
        } else if(p.child == 3) {
            st.pop();
        }
    }
    return root;
}

Node *createTree3(vector<int> &a) {
    int n = a.size();
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
    return root;
}

int main() {
    vector<int> a{50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};

    int ind = 0;
    Node* root1 = createTree1(a, ind);
    display(root1);
    cout << endl;

    Node* root2 = createTree2(a);
    display(root2);
    cout << endl;

    Node* root3 = createTree3(a);
    display(root3);
    cout << endl;

    return 0;
}