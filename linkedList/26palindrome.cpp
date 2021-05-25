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
    Node* pre = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

bool palindrome(Node* head) {
    if(!head || !head->next) return true;
    Node* mid = midNode(head);
    Node* headRev = reverse(mid->next);
    mid->next = NULL;

    Node* c1 = head;
    Node* c2 = headRev;
    bool isPalindrome = true;
    while(c2 != NULL) {
        if(c1->data != c2->data) {
            isPalindrome = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    mid->next = reverse(headRev);
    return isPalindrome;
}

int main() {
    Node* head = NULL;
    head = addFirst(head, 7);
    head = addFirst(head, 6);
    head = addFirst(head, 5);
   
    head = addFirst(head, 5);
    head = addFirst(head, 6);
    head = addFirst(head, 7);
    display(head);
    cout << (palindrome(head) ? "true" : "false") << endl;
   
    return 0;
}