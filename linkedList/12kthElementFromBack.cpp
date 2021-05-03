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
    int getSize() {
        return size;
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
    void addFirst(int data) {
        Node* node = new Node(data);
        if(size == 0) {
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }
        size++;
    }
    void addAtIndex(int pos, int data) {
        if(pos == 0) {
            addFirst(data);
        } else if(pos == size) {
            addLast(data);
        } else if(pos < 0 || pos > size) {
            cout << "invalid arguments " << endl;
            return;
        } else {
            Node* node = new Node(data);
            Node* temp = head;
            for(int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            size++;
        }
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
    void removeLast() {
        if(size == 0) {
            return;
        } else if(size == 1) {
            Node* toRemove = head;
            head = tail = NULL;
            delete toRemove;
        } else {
            Node* temp = head;
            for(int i = 1; i < size-1; i++) {
                temp = temp->next;
            }
            Node* toRemove = temp->next;
            temp->next = NULL;
            tail = temp;
            delete toRemove;
        }
        size--;
    }
    void removeAtIndex(int pos) {
        if(pos < 0 || pos >= size) {
            cout << "invalid arguments " << endl;
            return;
        } else if(pos == 0) {
            removeFirst();
        } else if(pos == size-1) {
            removeLast();
        } else {
            Node* temp = head;
            for(int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* toRemove = temp->next;
            temp->next = toRemove->next;
            delete toRemove;
            size--;
        }
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
    void reverseIterative() {
        Node* prev = NULL;
        Node* curr = head;
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail = head;
        head = prev;
    }
    Node* getNodeAt(int pos) {
        Node* temp = head;
        for(int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp;
    }
    void reverseData() {
        int i = 0;
        int j = size-1;
        while(i < j) {
            Node* a = getNodeAt(i);
            Node* b = getNodeAt(j);
            int temp;
            temp = a->data;
            a->data = b->data;
            b->data = temp;
            i++;
            j--;
        }
    }
    //without using size property
    int kthElementFromLast(int k) {
        Node* front = head;
        for(int i = 0; front != NULL, i < k; i++) {
            front = front->next;
        }
        if(front) {
            Node* rear = head;
            while(front != tail) {
                front = front->next;
                rear = rear->next;
            }
            return rear->data;
        } else {
            cout << "invalid argument " << endl;
            return -1;
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
    list.addFirst(23);
    list.addFirst(33);
    list.addFirst(13);
    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(55);
    list.display();
    cout << list.kthElementFromLast(0) << endl;
    cout << list.kthElementFromLast(1) << endl;
    cout << list.kthElementFromLast(2) << endl;

    return 0;
}