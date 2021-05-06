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

// void levelOrderNewLine(Node* root) {
//     queue<Node*> q;
//     queue<Node*> hq;
//     q.push(root);
//     while(!q.empty()) {
//         Node* node = q.front();
//         q.pop();
//         cout << node->data << " ";
//         for(auto child : node->children) {
//             hq.push(child);
//         }
//         if(q.empty()) {
//             cout << endl;
//             queue<Node*> temp;
//             q = hq; //copy the summary and also the queue memory
//             hq = temp; //copy the summary and also the queue memory and delte prvious value
//         }
//     }
//     cout << "." << endl;
// }

//faster way to implement this to avoid copying queeus instead point to new one
void levelOrderNewLine(Node* root) {
    queue<Node*> *q = new queue<Node*>();
    queue<Node*> *hq = new queue<Node*>();
    q->push(root);
    while(!q->empty()) {
        Node* node = q->front();
        q->pop();
        cout << node->data << " ";
        for(auto child : node->children) {
            hq->push(child);
        }
        if(q->empty()) {
            cout << endl;
            queue<Node*> *temp = new queue<Node*>();
            delete q;
            q = hq;
            hq = temp;
        }
    }
    cout << "." << endl;
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
    levelOrderNewLine(root);
    return 0;
}