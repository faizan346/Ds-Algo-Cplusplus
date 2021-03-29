#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* next;
    int data;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

class Queue {
    int length;
    Node* first;
    Node* last;
    public:
        Queue() {
            length = 0;
            first = NULL;
            last = NULL;
        }
        void enqueue(int value){
            Node* node = new Node(value);
            if(length == 0) {
                first = last = node;
            } else {
                last->next = node;
                last = node;
            }
            length++;
        }
        void dequeue() {
            if(length == 0) return;
            Node* unWantedNode = first;
            first = first->next;
            if(length == 1) last = NULL;
            delete unWantedNode;
            length--;
        }
        int top(){
            return first->data;
        }
        void display() {
            Node* it = first;
            while(it) {
                cout << it->data << " ";
                it = it->next;
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(23);
    q.enqueue(84);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
      q.display();
        q.enqueue(5);
    q.enqueue(23);
    q.enqueue(84);
    q.display();
    q.dequeue();
    q.dequeue();
 q.display();
    cout << q.top() << endl;
    return 0;
}