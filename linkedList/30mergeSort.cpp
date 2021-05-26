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
    tail3->next = c1 ? c1 : c2;
    return dummy->next;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* mid = midNode(head);
    Node* headlh = head;
    Node* headrh = mid->next;
    mid->next = NULL;

    headlh = mergeSort(headlh);
    headrh = mergeSort(headrh);

    Node* sortedList = mergeTwoSortedLists(headlh, headrh);
    return sortedList;
}

int main() {
    int n;
    cin >> n;
    Node* head = createList(n);
    head = mergeSort(head);
    display(head);
    return 0;
}