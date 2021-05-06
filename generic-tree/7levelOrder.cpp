#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*> children;
    Node(int data) {
        this->data = data;
    }
};

void display(Node* node) {
    cout << node->data << " -> ";
    for(auto child : node->children) {
        cout << child->data << ", ";
    }
    cout << "." << endl;
    for(auto child : node->children) {
        display(child);
    }
}

int sizeTree(Node* node) {
    int size = 1;
    for(auto child : node->children) {
        size = size + sizeTree(child);
    }
    return size;
}

int maxValue(Node* node) {
    int max = node->data;
    for(auto child : node->children) {
        int cmax = maxValue(child);
        if(max < cmax) {
            max = cmax;
        }
    }
    return max;
}

int heightTree(Node* node) {
    int height = 0;
    for(auto child : node->children) {
        int hmax = heightTree(child) + 1;
        height = max(height, hmax);
    }
    return height;
}

void traversal(Node* node) {
    cout << "Node Pre " << node->data << endl;
    for(auto child : node->children) {
        cout << "Edge Pre " << node->data << "--" << child->data << endl;
        traversal(child);
        cout << "Edge Post " << node->data << "--" << child->data << endl;
    }
    cout << "Node Post " << node->data << endl;
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        for(auto child : node->children) {
            q.push(child);
        }
    }
    cout << "." << endl;
}

int main() {
    int a[] = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40 , -1, -1};
    int n = sizeof(a)/sizeof(a[0]);

    stack<Node*> st;
    Node* root;
    for(int i =0; i < n; i++) {
        if(a[i] == -1) {
            st.pop();
        } else {
            Node *node = new Node(a[i]);
            if(st.empty()) {
                //make the node root as stack is empty
                root = node;
            } else {
                //make child of previous node
                Node* top = st.top();
                top->children.push_back(node);
            }
            //finally push that node to stack
            st.push(node);
        }
    }
    levelOrder(root);
    return 0;
}