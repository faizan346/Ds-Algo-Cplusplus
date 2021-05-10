#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l = NULL, Node* r = NULL) {
        data = d;
        left = l;
        right = r;
    }
};

Node* constructor(int* a, int l, int r) {
    if(l > r) {
        return NULL;
    }
    int mid = (l+r)/2;
    int data = a[mid];
    Node* ln = constructor(a, l, mid-1);
    Node* rn = constructor(a, mid+1, r);

    Node* node = new Node(data, ln, rn);
    return node;
}

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

int main() {
    int a[] = {12,25,37,50,62,75,87};
    int n = sizeof(a)/sizeof(a[0]);
    Node* root = constructor(a, 0, n-1);
    display(root);
    return 0;
}