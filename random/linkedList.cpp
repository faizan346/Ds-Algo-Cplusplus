#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    Node* tail;
    int length;
    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    int getLength() {
        return length;
    }
    void append(int value) {
        Node* node = new Node;
        node->data = value;
        if(!head) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        length++;
    }
    void prepend(int value) {
        Node* node = new Node;
        node->data = value;
        // if(!head) {
        //     head = node;
        //     tail = node;
        // }
        //else {
            if(length == 0) tail = node;
            node->next = head; // this covering empty head case too.
            head = node;
       // }
        length++;
    }
    void deleteStart() {
        if(!head) return;
        Node* temp = head;
        if(tail == head) tail = NULL;
        head = head->next;
        delete temp;
        length--;
    }
    void deleteLast() {
        deletePos(length-1);
    }
    void insertPos(int pos, int value) {
        if(pos < 0 || pos > length) return;
        if(pos == length || length == 0) return append(value);
        if(pos == 0) {
            return prepend(value);
        }
        Node* node = new Node;
        node->data = value;
        Node* temp = head;
        int behindIdx = 1; //it tells us which idx temp is behind of..
        while(behindIdx < pos) {
            temp = temp->next;
            behindIdx++;
        }
        node->next = temp->next;
        temp->next = node;
        length++;
    }
    void deletePos(int pos) {
        if(pos < 0 || pos > length-1 || !head) return;
        Node* temp = head;
        if(pos == 0) {
            return deleteStart();
        }
        int behindIdx = 1;
        while(behindIdx < pos) {
            temp = temp->next;
            behindIdx++;
        }
        Node* tempDelete = temp->next;
        temp->next = tempDelete->next;
        delete tempDelete;
        if(pos == length-1) tail = temp; //equals temp->next == NULL
        length--;
    }
    void reverse() {
        Node* currNode = head;
        Node* prevNode = NULL;
        while(currNode) {
            Node* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        tail = head;
        head = prevNode;
    }
    void printList() {
        Node* temp = head;
        while(temp) {
            cout << temp->data<< " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.append(0);
    list.deleteStart();
    list.printList();
    list.append(2);
    list.append(1);
    list.append(3);
    list.append(1);
    list.printList();
   list.reverse();
   list.printList();
    cout << list.getLength()<<endl;
    return 0;
}