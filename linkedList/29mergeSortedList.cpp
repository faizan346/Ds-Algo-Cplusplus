#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

Node* createList(int n) {
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        prev->next = new Node(v);
        prev = prev->next;
    }
    return dummy->next;
}

void display(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

Node* mergeTwoSortedLists(Node* head1, Node* head2) {
    Node* c1 = head1;
    Node* c2 = head2;
    Node* dummy = new Node(-1);
    Node* tail3 = dummy;
    while(c1 != NULL && c2 != NULL) {
        if(c1->data <= c2->data) {
            tail3->next = c1;
            tail3 = c1;
            c1 = c1->next;
        } else {
            tail3->next = c2;
            tail3 = c2;
            c2 = c2->next;
        }
    }
    if(c1 != NULL) {
        tail3->next = c1;
    }
    if(c2 != NULL) {
        tail3->next = c2;
    }
    return dummy->next;
}

int main() {
    int n;
    cin >> n;
    Node* head1 = createList(n);
    int m;
    cin >> m;
    Node* head2 = createList(m);
    Node* head3 = mergeTwoSortedLists(head1, head2);
    display(head3);
    return 0;
}