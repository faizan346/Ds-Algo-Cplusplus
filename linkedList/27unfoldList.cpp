#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
    }
};

void display(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}

Node* addFirst(Node* head, int data) {
    Node* node = new Node(data);
    if(head == NULL) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }
    return head;
}

Node* midNode(Node* head) {
    Node* s = head;
    Node* f= head;
    while(f->next != NULL && f->next->next != NULL) {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void foldLinkedList(Node* head) {
    if(!head || !head->next) return;
    Node* mid = midNode(head);
    Node* headRev = reverse(mid->next);
    mid->next = NULL;

    Node* l1 = head;
    Node* l2 = headRev;
    while(l2 != NULL) {
        Node* t1 = l1->next;
        Node* t2 = l2->next;

        l1->next = l2;
        l2->next = t1;

        l1 = t1;
        l2 = t2;
    }
}

void unFoldLinkedList(Node* head) {
    if(!head || !head->next) return;
    Node* lhHead = head;
    Node* rhHead = lhHead->next;
    
    Node* c1 = lhHead;
    Node* c2 = rhHead;
    while(c2 != NULL && c2->next != NULL) {
        Node* f = c2->next;
        c1->next = f;
        c1 = f;
        c2->next = f->next;
        c2 = f->next;
    }
    c1->next = NULL;
    
    rhHead = reverse(rhHead);
    c1->next = rhHead;
}

int main() {
    Node* head = NULL;
    head = addFirst(head, 7);
    head = addFirst(head, 6);
    head = addFirst(head, 5);
    head = addFirst(head, 4);
    head = addFirst(head, 3);
    head = addFirst(head, 2);
    head = addFirst(head, 1);
    display(head);
    foldLinkedList(head);
    display(head);
    unFoldLinkedList(head);
    display(head);
    return 0;
}