#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* head;
    int length;
    public:
    Stack() {
        head = NULL;
        length = 0;
    }
    int getLength() {
        return length;
    }
    void push(int value) {
        Node* node = new Node;
        node->data = value;
        node->next = head;
        head = node;
        length++;
    }
    int pop() {
        if(!head) return -1;
        Node* temp = head;
        head = head->next;
        int value = temp->data;
        delete temp;
        length--;
        return value;
    }
    int top() {
        return head->data;
    }
    bool isEmpty() {
      return  !head ? true : false;
    }
     void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data<< " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.push(5);
    s.push(29);
    s.push(5);
    s.push(29);
    s.display();
    s.pop();
    s.display();
    cout << s.top() << endl <<s.getLength()<<endl << s.isEmpty()<<endl;
    return 0;
}