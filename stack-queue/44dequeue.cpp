#include<bits/stdc++.h>
using namespace std;

template <class T>
class MyCircularDeque {
    class Node {
        public:
        Node *next = NULL, *prev = NULL; 
        T data;
        Node(){}
        Node(T val) {data = val;}
    };

    Node *front;
    Node *rear;

    public:
    /** Initialize your data structure here.*/
    MyCircularDeque() {
        front = new Node();
        rear = new Node();
        front->next = rear;
        rear->prev = front;
    }

    /**
     * Adds an item at the front of Deque.
     */
    void insertFront(T value) {
        Node *node = new Node(value);
        node->prev = front;
        node->next = front->next;
        front->next->prev = node;
        front->next = node;
    }

    /**
     * Adds an item at the rear of Deque.
     */
    void insertLast(T value) {
        Node *node = new Node(value);
        node->next = rear;
        node->prev = rear->prev;
        rear->prev->next = node;
        rear->prev = node;
    }

    /**
     * Deletes the front item from the Deque and return it's value. If the deque is empty, return null.
     */
    string deleteFront() {
        if(front->next == rear) return "null";
        Node *toRemove = front->next;
        front->next = toRemove->next;
        toRemove->next->prev = front;
        T data = toRemove->data;
        delete toRemove;
        return to_string(data);
    }

    /**
     * Deletes the last item from Deque and return it's value. If the deque is empty, return null.
     */
    string deleteLast() {
        if(front->next == rear) return "null";
        Node *toRemove = rear->prev;
        toRemove->prev->next = rear;
        rear->prev = toRemove->prev;
        T data = toRemove->data;
        delete toRemove;
        return to_string(data);
    }

    /** Gets the front item from the Deque. If the deque is empty, return null. */
    string getFront() {
        if(front->next == rear) return "null";
        return to_string(front->next->data);
    }

    /** Gets the last item from Deque. If the deque is empty, return null. */
    string getRear() {
        if(front->next == rear) return "null";
        return to_string(rear->prev->data);
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(front->next == rear) return true;
        return true;
    }
};

int main() {
    string s;
    MyCircularDeque<int> dq;
    while(getline(cin, s)) {
        stringstream ss(s);
        string word;
        ss >> word;
        if (word == ("insertLast")) {
            int data;
            ss >> data;
            dq.insertLast(data);
        } else if (word == ("insertFront")) {
            int data;
            ss >> data;
            dq.insertFront(data);
        } else if (word == ("deleteFront")) {
            cout << dq.deleteFront() << endl;
        } else if (word == ("deleteLast")) {
            cout << dq.deleteLast() << endl;
        } else if (word == ("getFront")) {
            cout << dq.getFront() << endl;
        } else if (word == ("getRear")) {
            cout << dq.getRear() << endl;
        } else if (word == ("isEmpty")) {
            cout << dq.isEmpty() << endl;
        }
    }
    return 0;
}


