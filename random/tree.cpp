#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    int data;
    Node(int value) {
        data = value;
    }
};

class BinarySearchTree {
    Node* root;
    public:
    BinarySearchTree() {
        root = NULL;
    }
    // void insertHelper(Node* &root, int value) {
    // if(!root) root = new Node(value);
    // else if(value > root->data) insertHelper(root->right, value);
    // else insertHelper(root->left, value);
    // }
    Node* insertHelper(Node* root, int value) {
        if(!root) root = new Node(value);
        else if(value > root->data) root->right = insertHelper(root->right, value);
        else root->left = insertHelper(root->left, value);
        return root;
    }
    void insert(int value) {
        root = insertHelper(root, value);
        //insertHelper(root,value);
    }
    // void insert(int value) {
    //     Node* node = new Node(value);
    //     if(!root) {
    //         root = node;
    //     } else {
    //         Node *temp, *leaf;
    //         temp = root;
    //         while(temp) {
    //             leaf = temp;
    //             if(temp->data < value)
    //                 temp = temp->right;
    //             else 
    //                 temp = temp->left;
    //         }
    //         if(leaf->data < value) leaf->right = node;
    //         else leaf->left = node;
    //     }
    // }
    bool lookUp(int value) {
        Node* temp = root;
        while(temp) {
            if(temp->data < value) {
               temp =  temp->right;
            } else if(temp->data > value){
               temp = temp->left;
            } else {
                return true;
            }
        }
        return false;
    }

    Node* minNodeRight(Node* root) {
        Node* temp = root;
        while(temp && temp->left) {
            temp = temp->left;
        }
        return temp;
    }

    void remove(int value) {
       Node* temp = root; //temp is finding root to delete
       Node* parent = NULL;
       while(temp) {
           if(temp->data > value) {
               parent = temp;
               temp = temp->left;
           } else if(temp->data < value) {
               parent = temp;
               temp = temp->right;
           } else {
                if(!temp->left && !temp->right) {
                    if(root == temp) root = NULL;
                    if(parent) { //although when we delete root there is no parent so we can provide else here too
                        if(parent->data < value) parent->right = NULL;
                        else parent->left = NULL;
                    }
                     delete temp;
                } else if(temp->left && !temp->right) {
                    if(root == temp) root = temp->left;
                    if(parent) {
                        if(parent->data < value) parent->right = temp->left;
                        else parent->left = temp->left;
                    }
                     delete temp;
                } else if(!temp->left && temp->right) {
                    if(root == temp) root = temp->right;
                    if(parent) {
                        if(parent->data < value) parent->right = temp->right;
                        else parent->left = temp->right;
                    }
                     delete temp;
                } else {
                    Node* minNode = minNodeRight(temp->right);
                    int data = minNode->data;
                    remove(minNode->data); // it is going to use the 1 or 2 case only. as it could have zero or one right child
                    temp->data = data;
                }
                return;
           }
       }
    }

    Node*& getRoot() {
        return root;
    }

    void traverse() {
        traverseHelper(root);
    }
    void traverseHelper(Node *node) {
        if(node == NULL) return;
        cout << "(" << node->data;
        traverseHelper(node->left);
        traverseHelper(node->right);
        cout << ")";
    }
};

int main() {
    BinarySearchTree b;
    b.insert(9);
    b.insert(4);
    b.insert(6);
    b.insert(20);
    b.insert(150);
    b.insert(160);
    b.insert(170);
    b.insert(155);
    b.insert(15);
    b.insert(1);
    b.traverse();
    b.remove(20);
    cout << endl;
    b.traverse();
     cout << endl;
    b.remove(4);
      b.traverse();
     cout << endl;
    return 0;
}

        //         9
        //     4       20
        // 1     6  15     150
        //                    160
        //               155         170
