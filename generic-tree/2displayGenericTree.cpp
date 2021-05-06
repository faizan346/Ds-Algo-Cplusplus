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

int main() {
    int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
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
    display(root);
    return 0;
}