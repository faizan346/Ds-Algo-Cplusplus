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

Node* removeNode(Node* root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(data < root->data) {
        root->left = removeNode(root->left, data);
    } else if(data > root->data) {
        root->right = removeNode(root->right, data);
    } else {
        if(!root->left && !root->right) {
            Node* toRemove = root;
            delete toRemove;
            return NULL;
        } else if(root->left && !root->right) {
            Node* toRemove = root;
            root = root->left;
            delete toRemove;
        } else if(!root->left && root->right) {
            Node* toRemove = root;
            root = root->right;
            delete toRemove;
        } else {
            int minRight = min(root->right);
            root->data = minRight;
            root->right = removeNode(root->right, minRight);
        }
    }
    return root;
}

void replacetoSumOfLarger(Node* root, int& sum) {
    if(root == NULL) return;
    replacetoSumOfLarger(root->right, sum);
    int val = root->data;
    root->data = sum;
    sum += val;
    replacetoSumOfLarger(root->left, sum);
}    

int lowestCommonAncestor(Node* root, int a, int b) {
    if(root == NULL) return -1;
    if(a < root->data && b < root->data) {
        return lowestCommonAncestor(root->left, a, b);
    } else if(a > root->data && b > root->data) {
        return lowestCommonAncestor(root->right, a, b);
    } else {
        return root->data;
    }
}

void printInRange(Node* root, int a, int b) { // sorted order also
    if(root == NULL) return;
    if(root->data > a || root->data > b) { // a ya b mai se koi bhi chota bda ho sakta hai
        printInRange(root->left, a, b);
    }
    if((root->data >= a && root->data <= b) || (root->data <= a && root->data >= b)) {
        cout << root->data << " ";
    }
    if(root->data < a || root->data < b) {
        printInRange(root->right, a, b);
    }
}

//o(h) space but o(nh) time
void printTargetSum1(Node* root, Node* node, int sum) {
    if(node == NULL) return;
    printTargetSum1(root, node->left, sum);
    int complement = sum - node->data;
    if(complement > node->data) { //becoz we dont want to print dublicates 
        if(find(root, complement)) {
            cout << node->data << " " << complement << endl;
        }
    }
    printTargetSum1(root, node->right, sum);
}

void travelInorderStore(Node* root, vector<int>& v) {
    if(root == NULL) return;
    travelInorderStore(root->left, v);
    v.push_back(root->data);
    travelInorderStore(root->right,v);
}

//O(n) time but o(n) space 
void printTargetSum2(Node* root, int sum) {
    vector<int> v;
    travelInorderStore(root, v);
    int i = 0;
    int j = v.size() - 1;
    while(i < j) {
        if(v[i] + v[j] == sum) {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        } else if(v[i] + v[j] > sum) {
            j--;
        } else {
            i++;
        }
    }
}

class PairIt {
    public:
    int state;
    Node* node;
    PairIt(Node* n, int s) {
        node = n;
        state = s;
    }
};

Node* getNextInorder(stack<PairIt>& sl) {
    while(!sl.empty()) {
        PairIt &p = sl.top();
        sl.top();
        if(p.state == 1) { //pre, push ,state++
            if(p.node->left != NULL) {
                sl.push(PairIt(p.node->left, 1));
            }
            p.state++;
        } else if(p.state == 2) { //in, push, state++
            if(p.node->right != NULL) {
                sl.push(PairIt(p.node->right, 1));
            }
            p.state++;
            return p.node; //giving state 2 node which in inorder sorted
        } else if(p.state == 3) { //post, pop
            sl.pop();
        }
    }
    return NULL;
}

Node* getNextReverseInorder(stack<PairIt>& sr) {
    while(!sr.empty()) {
        PairIt &p = sr.top();
        sr.top();
        if(p.state == 1) { //pre, push ,state++
            if(p.node->right != NULL) {
                sr.push(PairIt(p.node->right, 1));
            }
            p.state++;
        } else if(p.state == 2) { //in, push, state++
            if(p.node->left != NULL) {
                sr.push(PairIt(p.node->left, 1));
            }
            p.state++;
            return p.node; //giving state 2 node which in inorder sorted
        } else if(p.state == 3) { //post, pop
            sr.pop();
        }
    }
    return NULL;
}
//optimized it is taking o(h) space and o(n) time
void printTargetSum3(Node* root, int sum) {
    stack<PairIt> sl;
    stack<PairIt> sr;
    sl.push(PairIt(root, 1));
    sr.push(PairIt(root, 1));

    Node* left = getNextInorder(sl);
    Node* right = getNextReverseInorder(sr);
    while(left != right) {
        if(left->data + right->data == sum) {
            cout << left->data << " " << right->data << endl;
            left = getNextInorder(sl);
            right = getNextReverseInorder(sr);
        } else if(left->data + right->data < sum) {
            left = getNextInorder(sl);
        } else {
            right = getNextReverseInorder(sr);
        }
    }
}

int main() {
    int a[] = {12,25,30,37,40,50,60,62,70,75,87};
    int n = sizeof(a)/sizeof(a[0]);
    Node* root = constructor(a, 0, n-1);
    printTargetSum3(root, 100);
    return 0;
}