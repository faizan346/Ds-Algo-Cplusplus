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

int size(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

int sum(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}

int max(Node* root) {
    if(root == NULL) {
        return INT_MIN;
    }
    if(root->right == NULL) {
        return root->data;
    }
    return max(root->right);
}

int min(Node* root) {
    if(root == NULL) {
        return INT_MAX;
    }
    if(root->left == NULL) {
        return root->data;
    }
    return min(root->left);
}

bool find(Node* root, int data) {
    if(root == NULL) {
        return false;
    }
    if(data == root->data) {
        return true;
    } else if(data > root->data) {
        return find(root->right, data);
    } else {
        return find(root->left, data);
    }
}

Node* addNode(Node* root, int data) {
    if(root == NULL) {
        Node* node = new Node(data, NULL, NULL);
        return node;
    }
    if(data < root->data) {
        root->left = addNode(root->left, data);
    } else if(data > root->data) {
        root->right = addNode(root->right, data);
    }
    return root;
}
    
int main() {
    int a[] = {12,25,37,50,62,75,87};
    int n = sizeof(a)/sizeof(a[0]);
    Node* root = constructor(a, 0, n-1);
    root = addNode(root, 65);
    display(root);
    return 0;
}