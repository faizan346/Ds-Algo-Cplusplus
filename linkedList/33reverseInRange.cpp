#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;
    Node(int data) {
        this->data = data;
    }
};

Node* createList(int n) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    for(int i = 0 ; i < n; i++) {
        int data;
        cin >> data;
        temp->next = new Node(data);
        temp = temp->next;
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

Node* reverse(Node* head) {
    Node* pre = NULL;
    Node* curr = head;
    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

Node* reverseRange(Node* head, int l, int r) {
    if(head == NULL || head->next == NULL || l == r) return head;
    Node* headcPre = NULL;
    Node* headc = head;
    Node* tailc = head;
    for(int i = 0; i < l-1; i++) {
        headcPre = headc;
        headc = headc->next;
    }
    for(int i = 0; i < r-1; i++) {
        tailc = tailc->next;
    }
    Node* tailcNext = tailc->next;
    if(headcPre != NULL) headcPre->next = NULL;
    else head = tailc;
    tailc->next = NULL;
    tailc = headc;
    headc = reverse(headc);
    if(headcPre != NULL) headcPre->next = headc;
    tailc->next = tailcNext;
    return head;
}
int main() {
    int n;
    cin >> n;
    Node* head = createList(n);
    int l, r;
    cin >> l >> r;
    head = reverseRange(head, l, r);
    display(head);
    return 0;
}