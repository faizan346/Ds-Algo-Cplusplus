#include<bits/stdc++.h>
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

class LinkedList {
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void addLast(int data) {
        Node* node = new Node(data);
        if(size == 0) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }
    void removeFirst() {
        if(size == 0) {
            return;
        }
        Node* toRemove = head;
        if(size == 1) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        delete toRemove;
        size--;
    }
    int getFirst() {
        if(size == 0) {
            cout << "list is empty" << endl;
            return -1;
        } else {
            return head->data;
        }
    }
    int getLast() {
        if(size == 0) {
            cout << "list is empty" << endl;
            return -1;
        } else {
            return tail->data;
        }
    }
    int getAt(int pos) {
        if(size == 0) {
            cout << "list is empty" << endl;
            return -1;
        } else if(pos >= size || pos < 0) {
            cout << "invalid arguments" << endl;
            return -1;
        } else {
            Node* temp = head;
            for(int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }
    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.addLast(34);
    list.addLast(53);
    list.addLast(61);
    list.addLast(12);
    list.addLast(89);
    list.addLast(48);
    list.display();
    cout << list.getFirst() << endl;
    cout << list.getLast() << endl;
    cout << list.getAt(-1) << endl;
    cout << list.getAt(10) << endl;
    cout << list.getAt(2) << endl;

    return 0;
}