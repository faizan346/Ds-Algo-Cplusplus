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
//             hq = temp; //copy the summary and also the queue memory and delete prvious value
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

void levelOrderZigZag(Node* root) {
    queue<Node*> *q = new queue<Node*>();
    stack<Node*> *hs = new stack<Node*>();
    int level = 0;
    q->push(root);
    while(!q->empty()) {
        Node* node = q->front();
        q->pop();
        cout << node->data << " ";
        if(level%2 == 0) {
            for(auto child : node->children) {
                hs->push(child);
            }
        } else {
            for(auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                hs->push(*it);
            }
        }
        
        if(q->empty()) {
            cout << endl;
            level++;
            while(!hs->empty()) {
                q->push(hs->top());
                hs->pop();
            }
        }
    }
    cout << "." << endl;
}

void levelOrderWithNull(Node* root) {
    queue<Node*> *q = new queue<Node*>();
    q->push(root);
    q->push(NULL);
    while(!q->empty()) {
        Node *node = q->front();
        q->pop();
        if(node == NULL) {
            if(!q->empty()) {
                q->push(NULL);
            }
            cout << endl;
            continue;
        }
        cout << node->data << " ";
        for(auto child : node->children) {
            q->push(child);
        }
    }
    cout << "." << endl;

}

void levelOrderWithQueueSize(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int queueSize = q.size(); // take the current size of queue
        for(int i = 0; i < queueSize; i++) { // queue will runn these many time before next level
            Node *node = q.front();
            q.pop();
            for(auto child : node->children) { // push child of every node in same level.
                q.push(child);
            }
            cout << node->data << " ";
        }
        cout << endl; // after completing the level move to next line
    }
    cout << "." << endl;
}

class Pair {
    public:
    Node* node;
    int level;
    Pair(Node* n, int l) {
        node = n;
        level = l;
    }
};

void levelOrderWitPair(Node* root) {
    queue<Pair> q;
    q.push(Pair(root, 0));
    int level = 0;
    while(!q.empty()) {
        Pair p = q.front();
        q.pop();
        if(level != p.level) { // give endline if not same level
            level = p.level;    //make the level to curr level;
            cout << endl;
        }
        cout << p.node->data << " ";
        for(auto child : p.node->children) {
            q.push(Pair(child, level + 1));
        }
    }
    cout << "\n." << endl;
}

void mirror(Node* node) {
    for(auto child : node->children) {
        mirror(child);
    }
    reverse(node->children.begin(), node->children.end());
}

void removeLeaves(Node* node) {
    for(int i = node->children.size()-1; i >= 0; i--) {
        Node* child = node->children[i];
        if(child->children.empty()) {
            node->children.erase(node->children.begin() + i);
        }
    }
    for(auto child : node->children) {
        removeLeaves(child);
    }
}

Node *getTail(Node* node) {
    while(node->children.size() > 0) {
        node = node->children.front();
    }
    return node;
}
//o(n^2) time
void linearizeTheTree(Node* node) {
    for(auto child : node->children) {
        linearizeTheTree(child);
    }
    
    while(node->children.size() > 1) {
        Node *lchild = node->children.back();
        node->children.pop_back();
        Node *slChild = node->children.back();
        Node *slTail = getTail(slChild);
        slTail->children.push_back(lchild);
    }

}

//no exta space o(n) time
Node* linearize(Node* node) {
    if(node->children.empty()) {
        return node;
    }
    Node* nodeLast = linearize(node->children.back());
    while(node->children.size() > 1) {
        Node *last = node->children.back(); //save last element
        node->children.pop_back(); // remove last element
        Node *slChild = node->children.back(); // secondLast of rem child
        Node *slChildLastChild = linearize(slChild); // it's last child after linearize
        slChildLastChild->children.push_back(last); //sl last child point to last child

    }
    return nodeLast;
}

int search(Node* node, int toFind) {
    if(node->data == toFind) {
        return true;
    }
    for(auto child : node->children) {
        if(search(child, toFind)) {
            return true;
        }
    }
    return false;
}

vector<int> nodeToRootPath(Node* node, int val) {
    if(node->data == val) {
        vector<int> path;
        path.push_back(node->data);
        return path;
    }
    for(auto child : node->children) {
        vector<int> pathChild = nodeToRootPath(child, val);
        if(!pathChild.empty()) {
            pathChild.push_back(node->data);
            return pathChild;
        }
    }
    return vector<int>();
}

class Pairlca {
    public:
    int data;
    int found;
    Pairlca(int d, int f) {
        data = d;
        found = f;
    }
};

//lca my approach
Pairlca lowestCommonAncestor(Node* node, int a, int b) {
    int found = 0;
    if(node->data == a || node->data == b) {
        found = found + 1;
    }
    for(auto child : node->children) {
        Pairlca cf = lowestCommonAncestor(child, a, b);
        if(cf.found == 2) {
            return cf;
        } else if(cf.found == 1) {
            found = found + cf.found;
        }
    }
    if(found == 2) {
        return Pairlca(node->data, found);
    }
    return Pairlca(0, found);
}
//lca sir's approach
int lca(Node* node, int a, int b) {
    vector<int> ntrpA = nodeToRootPath(node, a);
    vector<int> ntrpB = nodeToRootPath(node, b);
    int i = ntrpA.size() - 1;
    int j = ntrpB.size() - 1;
    while(i >= 0 && j >= 0) {
        if(ntrpA[i] != ntrpB[j]) {
            break;
        } 
        i--;
        j--;
    }
    int anc = ntrpA[i+1];
    return anc;
}

class PairDist {
    public:
    int dis;
    int found;
    PairDist(int d, int f) {
        dis = d;
        found = f;
    }
};

//distance between node my approach
PairDist distanceNodes(Node* node, int a, int b) {
    int found = 0;
    int dis = 0;
    if(node->data == a || node->data == b) {
        found = found + 1;
    }
    for(auto child : node->children) {
        PairDist cf = distanceNodes(child, a, b);
        if(cf.found == 2) {
            return cf;
        } else if(cf.found == 1) {
            found = found + cf.found;
            dis = dis + cf.dis + 1;
        }
    }
    return PairDist(dis, found);
}
//distance between node my sir's approach
int distanceBetweenNodes(Node* node, int a, int b) {
    vector<int> ntrpA = nodeToRootPath(node, a);
    vector<int> ntrpB = nodeToRootPath(node, b);
    int i = ntrpA.size() - 1;
    int j = ntrpB.size() - 1;
    while(i >= 0 && j >= 0) {
        if(ntrpA[i] != ntrpB[j]) {
            break;
        } 
        i--;
        j--;
    }
    i++;
    j++;

    return i+j;
}

bool similarShape(Node* node1, Node* node2) {
    if(node1->children.size() != node2->children.size()) {
        return false;
    }
    for(int i = 0; i < node1->children.size(); i++) {
        bool similar = similarShape(node1->children[i], node2->children[i]);
        if(!similar) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int b[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, -1, -1};

    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    stack<Node*> st;
    Node* root1;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            st.pop();
        } else {
            Node* node = new Node(a[i]);
            if(st.empty()){
                root1 = node;
            } else {
                Node* parent = st.top();
                parent->children.push_back(node);
            }
            st.push(node);
        }
    }
    Node* root2;
    for(int i = 0; i < m; i++) {
        if(b[i] == -1) {
            st.pop();
        } else {
            Node* node = new Node(a[i]);
            if(st.empty()) {
                root2 = node;
            } else {
                Node* parent = st.top();
                parent->children.push_back(node);
            }
            st.push(node);
        }
    }
    cout << (similarShape(root1, root2) ? "true" : "false") << endl;

    return 0;
}