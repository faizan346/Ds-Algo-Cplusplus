#include<bits/stdc++.h>
using namespace std;

class Queue {
    public:
    int front;
    int size;
    int cap;
    int *a;
    Queue(int capacity = 10) {
        cap = capacity;
        a = new int[cap];
        front = 0;
        size = 0;
    }
    void push(int v) {
        if(size == cap) {
            //cout << "overflow.." << endl;
            //expand dynamically
            int newCap = 2 * cap;
            int *newArray = new int[newCap];
            for(int i = 0; i < cap; i++) {
                newArray[i] = a[(front + i) % cap];
            }
            delete[] a;
            a = newArray;
            cap = newCap;
            front = 0;
            int rear = (front+size)%cap;
            a[rear] = v;
            size++;
        } else {
            int rear = (front+size)%cap;
            a[rear] = v;
            size++;
        }
    } 
    void pop() {
        if(size == 0) {
            cout << "underflow.." << endl;
        } else {
            front = (front+1)%cap;
            size--;
        }
    }
    int peek() {
        if(size == 0) {
            cout << "underflow.." << endl;
            return -1;
        } else {
            return a[front];
        }
    }
    bool empty() {
        if(size == 0) {
            return true;
        } else {
            return false;
        }
    }
    void display() {
        for(int i = 0; i < size; i++) {
            cout << a[(front+i)%cap] << " " ;
        }
        cout << endl;
    }

};

int main() {
    Queue q(5);
    q.push(2);
    q.push(5);
    q.push(6);
    q.pop();
    q.push(2);
    q.push(5);
    q.push(6);
    q.push(1);
    q.display();
    return 0;
}