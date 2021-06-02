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

Node* reverseK(Node* head, int k) {
    Node* rear = head;
    Node* front = head;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(front != NULL) {
        for(int i = 0; i < k-1; i++) {
            front = front->next;
            if(front == NULL) {
                break;
            }
        }
        if(front == NULL) {
            temp->next = rear;
        } else {
            Node* headc = rear;
            rear = front->next;
            front->next = NULL;
            front = rear;
            Node* tailc = headc;
            headc = reverse(headc);
            temp->next = headc;
            temp = tailc;
        }
    }
    return dummy->next;
}

int main() {
    int n;
    cin >> n;
    Node* head = createList(n);
    int k;
    cin >> k;
    head = reverseK(head, k);
    display(head);
    return 0;
}