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

Node* removeNthFromEnd(Node* head, int n) {
  Node* f = head;
  Node* curr = head;
  Node* pre = NULL;
  for(int i = 0 ; i < n; i++) {
      f = f->next;
  }
  while(f != NULL) {
      f = f->next;
      pre = curr;
      curr = curr->next;
  }
  if(pre == NULL) {
      head = curr->next;
  } else {
      pre->next = pre->next->next;
  }
  delete curr;
  return head;
}

int main() {
    int n;
    cin >> n;
    Node* head = createList(n);
    int k;
    cin >> k;
    head = removeNthFromEnd(head, k);
    display(head);
    return 0;
}