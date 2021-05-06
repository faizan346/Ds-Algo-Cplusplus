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
    int middleElement() {
        Node* front = head;
        Node* rear = head;
        while(front->next != tail && front != tail) {
            front = front->next->next;
            rear = rear->next;
        }
        return rear->data;
    }
    void removeDublicateSortedList() {
        LinkedList list;
        while(head != NULL) {
            if(list.head == NULL || head->data != list.getLast()) {
                list.addLast(head->data);
            } 
            removeFirst();
        }
        *this = list;
    }
    void oddEvenList() {
        LinkedList listEven;
        LinkedList listOdd;
        while(head) {
            if(head->data % 2 == 0) {
                listEven.addLast(head->data);
            } else {
                listOdd.addLast(head->data);
            }
            removeFirst();
        }
        if(listEven.size > 0 && listOdd.size > 0) {
            listOdd.tail->next = listEven.head;
            this->head = listOdd.head;
            this->tail = listEven.tail;
            this->size = listOdd.size + listEven.size;
        } else if(listOdd.size > 0) {
            this->head = listOdd.head;
            this->tail = listOdd.tail;
            this->size = listOdd.size;
        } else if(listEven.size > 0) {
            this->head = listEven.head;
            this->tail = listEven.tail;
            this->size = listEven.size;
        }

    }
    //wihout size
    void kReverseWihoutSize(int k) {
        LinkedList list;
        Node* f = head;
        Node* b = head;
        //moving to k-1th term as k is the size
        for(int i = 0; i < k-1; i++) {
            f = f->next;
        }
        while(f != tail) {
            LinkedList rev;
            for(int i = 0; i < k; i++) {
                rev.addFirst(b->data);
                if(f != tail) {
                    f = f->next;
                }
                b = b->next;
                //put this after b otherwise b would start pointing to null
                removeFirst();
            }
            if(list.head == NULL) {
                list = rev;
            } else {
                list.tail->next = rev.head;
                list.tail = rev.tail;
                list.size = list.size + k;
            }
        }
        while(b != NULL) {
            list.addLast(b->data);
            b = b->next;
            removeFirst();
        }
        *this = list;
    }
    //with size
    void kReverse(int k) {
        LinkedList list;
        while(size > 0) {
            LinkedList rev;
            if(size >= k) {
                for(int i = 0; i < k; i++) {
                    int val = getFirst();
                    rev.addFirst(val);
                    removeFirst();
                }
            } else {
                int remSize = size;
                for(int i = 0; i < remSize; i++) {
                    int val = getFirst();
                    rev.addLast(val);
                    removeFirst();
                }
            }
            if(list.head == NULL) {
                list = rev;
            } else {
                list.tail->next = rev.head;
                list.tail = rev.tail;
                list.size = list.size + k;
            }
        }
        *this = list;
    }
    void reverseRecursiveHelper(Node* head) {
        if(head == tail) {
            return;
        }
        reverseRecursiveHelper(head->next);
        head->next->next = head;
        head->next = NULL;
    }
    void reverseRecursive() {
        reverseRecursiveHelper(head);
        Node* temp = head;
        head = tail;
        tail = temp;
    }
    Node* reverseDataRecursiveHelper(Node* right, int i) {
        if(right == NULL) {
            Node* left = head;
            return left;
        }
        //should work only after middle element
        Node *left = reverseDataRecursiveHelper(right->next, i+1);
        if(i >= size/2) {
            int temp = right->data;
            right->data = left->data;
            left->data = temp;
            left = left->next;
        }
        return left;
    }
    void reverseDataRecursive() {
        reverseDataRecursiveHelper(head, 0);
    }
    bool palindromeHelper(Node* right, int i, Node* &left) {
        if(right == NULL) {
            left = head;
            return true;
        }
        bool flag = palindromeHelper(right->next, i+1, left);
        //should work only after middle element and flag is true
        if(i >= size/2 && flag) {
            if(left->data != right->data) {
                flag = false;
            }
            left = left->next;
        }
        return flag;
    }
    bool palindrome() {
        Node* right = head;
        Node* left;
        return palindromeHelper(right, 0, left);
    }
    void foldListHelper(Node* right, int i, Node* &left) {
        if(right == NULL) {
            left = head;
            return;
        }
        foldListHelper(right->next, i+1, left);
        if(i > size/2) {
            Node* leftNext = left->next;
            left->next = right;
            right->next = leftNext;
            left = leftNext;
        } else if(i == size/2) {
            //link of left to right is already there
            tail = right;
            tail->next = NULL;
        }
    }
    void foldList() {
        Node* left;
        Node* right = head;
        foldListHelper(right, 0, left);
    }
    LinkedList addTwoLinkedListHelper(LinkedList l1, Node* i, int n, LinkedList l2, Node* j, int m, int &c) {
        if(i == NULL && j == NULL) {
            LinkedList list;
            //return empty list;
            return list;
        }
        LinkedList list;
        if(n > m) {
            list = addTwoLinkedListHelper(l1, i->next, n-1, l2, j, m, c);
            int d = (i->data + c) % 10;
            c = (i->data + c) / 10;
            list.addFirst(d);
        } else if(n < m) {
            list = addTwoLinkedListHelper(l1, i, n, l2, j->next, m-1, c);
            int d = (j->data + c) % 10;
            c = (j->data + c) / 10;
            list.addFirst(d);
        } else if(n == m){
            list = addTwoLinkedListHelper(l1, i->next, n-1, l2, j->next, m-1, c);
            int d = (i->data + j->data + c) % 10;
            c = (i->data + j->data + c) / 10;
            list.addFirst(d);
        }
        return list;
    }
    LinkedList addTwoLinkedList(LinkedList l1, LinkedList l2) {
        int c = 0;
        LinkedList list = addTwoLinkedListHelper(l1, l1.head, l1.size, l2, l2.head, l2.size, c);
        if(c > 0) {
            list.addFirst(c);
        }
        return list;
    }
    Node* intersectionTwoList(LinkedList l1, LinkedList l2) {
        Node* t1 = l1.head;
        Node* t2 = l2.head;
        int diff = abs(l1.size - l2.size);
        if(l1.size > l2.size) {
            for(int i = 0; i < diff; i++) {
                t1 = t1->next;
            }
        } else if(l1.size < l2.size){
            for(int i = 0; i < diff; i++) {
                t2 = t2->next;
            }
        }
        while(t1 != t2) {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
        LinkedList mergeTwoSortedList(LinkedList &l1, LinkedList &l2) {
        LinkedList list3;
        while(l1.head && l2.head) {
            if(l1.getFirst() <= l2.getFirst()) {
                list3.addLast(l1.getFirst());
                l1.removeFirst();
            } else {
                list3.addLast(l2.getFirst());
                l2.removeFirst();
            }
        }
        while(l1.head) {
            list3.addLast(l1.getFirst());
            l1.removeFirst();
        }
        while(l2.head) {
            list3.addLast(l2.getFirst());
            l2.removeFirst();
        }
        return list3;
    }
    Node* middleNode(Node* head, Node* tail) {
        Node* front = head;
        Node* rear = head;
        while(front->next != tail && front != tail) {
            front = front->next->next;
            rear = rear->next;
        }
        return rear;
    }
    LinkedList mergeSort(Node* head, Node* tail) { 
        if(head == tail) {
            LinkedList list;
            list.addFirst(head->data);
            return list;
        }
        Node* mid = middleNode(head, tail);
        LinkedList lh = mergeSort(head, mid);
        LinkedList rh = mergeSort(mid->next, tail);
        LinkedList list = mergeTwoSortedList(lh, rh);
        return list;
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
    LinkedList list1, list2;
    list1.addLast(1);
    list1.addLast(7);
    list1.addLast(9);
    list1.addLast(4);
    list1.addLast(9);
    list1.addLast(5);
    list2.addLast(7);
    list2.addLast(9);
    list2.tail->next = list1.getNodeAt(3);
    list2.tail = list1.tail;
    list2.size = 5;
    list1.display();
    list2.display();
    cout << list1.intersectionTwoList(list1, list2)->data << endl;
    

    return 0;
}