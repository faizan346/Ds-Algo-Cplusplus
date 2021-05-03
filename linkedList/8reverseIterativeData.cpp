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
    list.addFirst(34);
    list.addFirst(52);
    list.addFirst(2);
    list.addFirst(12);
    list.display();
    list.reverseData();
    list.display();

    return 0;
}