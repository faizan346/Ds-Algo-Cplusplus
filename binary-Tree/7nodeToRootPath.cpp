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

void traverse(Node* root) {
    if(root == NULL) return;
    cout << root->data << " in preorder" << endl;
    traverse(root->left);
    cout << root->data << " in inorder" << endl;
    traverse(root->right);
    cout << root->data << " in postorder" << endl;
}

void levelOrder1(Node* root) {
    queue<Node*> q;
    queue<Node*> hq;
    q.push(root);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if(node->left) {
            hq.push(node->left);
        }
        if(node->right) {
            hq.push(node->right);
        }
        if(q.empty()) {
            cout << endl;
            q = hq; //copying will take some time 
            hq = queue<Node*>();
        }
    }
}

void levelOrder2(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
        cout << endl;
    }
}

void levelOrder3(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* node = q.front();
        q.pop();
        if(node == NULL) {
            cout << endl;
            if(q.empty()) {
                break;
            }
            q.push(NULL);
            continue;
        }
        cout << node->data << " ";
        if(node->left) {
            q.push(node->left);
        }
        if(node->right) {
            q.push(node->right);
        }
    }
}

class PairNodeState {
    public:
    Node* node;
    int state;
    PairNodeState(Node* n, int s) {
        node = n;
        state = s;
    }
};

void traversalIterative(Node* root) {
    stack<PairNodeState> st;
    st.push(PairNodeState(root, 1));
    while(!st.empty()) {
        PairNodeState &p = st.top();
        if(p.state == 1) { // pre, s++, left
            cout << p.node->data << " in Preoder" << endl;
            p.state++;
            if(p.node->left) {
                st.push(PairNodeState(p.node->left, 1));
            }
        } else if(p.state == 2) { // in, s++, right
            cout << p.node->data << " in inorder" << endl;
            p.state++;
            if(p.node->right) {
                st.push(PairNodeState(p.node->right, 1));
            }
        } else if(p.state == 3){ // post, pop
            cout << p.node->data << " in Postorder" << endl;
            st.pop();
        }
    }
}

vector<int> nodeToRoot(Node* root, int val) {
    if(root == NULL) {
        return vector<int>();
    }
    if(root->data == val) {
        return vector<int>(1, val);
    }
    if(root->left) {
        vector<int> ntrLeft = nodeToRoot(root->left, val);
        if(!ntrLeft.empty()) {
            ntrLeft.push_back(root->data);
            return ntrLeft;
        }
    }
    if(root->right) {
        vector<int> ntrRight = nodeToRoot(root->right, val);
        if(!ntrRight.empty()) {
            ntrRight.push_back(root->data);
            return ntrRight;
        }
    }
    return vector<int>();

}

int main() {
    int a[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int n = sizeof(a)/sizeof(a[0]);

    stack<Pair> st;
    Node* root;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) { // when null
            //hmlog stack se nikalkar update krenge childIndex
            // ko aur agar index mai 2 hogaya matlab no all child traversed pop krdo parent ko
            Pair &p = st.top();
            if(p.child == 0) {
                p.node->left = NULL;
                p.child++;
            } else if(p.child == 1){
                p.node->right = NULL;
                p.child++;
                st.pop();
            }
        } else { // when node push to stack while checking state of parent
            Node* node = new Node(a[i]);
            if(st.empty()) {// stack empty hai daldo node root bna ke
                root = node;
            } else {
                Pair &p = st.top();
                if(p.child == 0) {
                    p.node->left = node;
                    p.child++;
                } else if(p.child == 1){ // pop parent after filling right child
                    p.node->right = node;
                    p.child++;
                    st.pop();
                }
            }
            st.push(Pair(node, 0));
        }
    }
    vector<int> v = nodeToRoot(root, 30);
    for(auto x : v) cout << x << " ";
    cout << endl;
    return 0;
}