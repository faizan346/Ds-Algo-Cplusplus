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
    //without using size property
    int middleElement() {
        Node* front = head;
        Node* rear = head;
        while(front->next != tail && front != tail) {
            front = front->next->next;
            rear = rear->next;
        }
        return rear->data;
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

LinkedList mergeTwoSortedList(LinkedList l1, LinkedList l2) {
    Node* one = l1.head;
    Node* two = l2.head;
    LinkedList list3;
    while(one!=NULL && two!=NULL) {
        if(one->data <= two->data) {
            list3.addLast(one->data);
            one = one->next;
        } else {
            list3.addLast(two->data);
            two = two->next;
        }
    }
    while(one!=NULL) {
        list3.addLast(one->data);
        one = one->next;
    }
    while(two!=NULL) {
        list3.addLast(two->data);
        two = two->next;
    }
    return list3;
}

int main() {
    LinkedList list1, list2;
    list1.addLast(1);
    list1.addLast(8);
    list1.addLast(19);
    list1.addLast(30);
    list1.addLast(35);
    list1.addLast(49);
    list2.addLast(2);
    list2.addLast(9);
    list2.addLast(11);
    list2.addLast(90);
    LinkedList list3 = mergeTwoSortedList(list1, list2);
    list1.display();
    list2.display();
    list3.display();

    return 0;
}