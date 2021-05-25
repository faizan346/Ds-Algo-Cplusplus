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

void display(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
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

Node* evenOdd(Node* head) {
    Node* headEven = NULL;
    Node* tailEven = NULL;
    Node* headOdd = NULL;
    Node* tailOdd = NULL;
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data % 2 == 0) {
            if(tailEven == NULL) {
                headEven = tailEven = temp;
            } else {
                tailEven->next = temp;
                tailEven = temp;
            }
        } else {
            if(tailOdd == NULL) {
                headOdd = tailOdd = temp;
            } else {
                tailOdd->next = temp;
                tailOdd = temp;
            }   
        }
        temp = temp->next;
    }
    if(headEven && headOdd) {
        tailOdd->next = NULL;
        tailEven->next = headOdd;
        return headEven;
    } else if(headEven) {
        tailEven->next = NULL;
        return headEven;
    } else {
        tailOdd->next = NULL;
        return headOdd;
    }
}

int main() {
    int n;
    cin >> n;
    Node* head = NULL;
    Node* prev;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        if(head == NULL) {
            head = new Node(v);
            prev = head;
        } else {
            prev->next = new Node(v);
            prev = prev->next;
        }

    }
    head = evenOdd(head);
    display(head);
    return 0;
}