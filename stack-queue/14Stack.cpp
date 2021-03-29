#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int tos;
    int cap;
    int *a;
    Stack(int capacity = 10) {
        cap = capacity;
        a = new int[cap];
        tos = -1;
    }
    int size() {
        return tos + 1;
    }
    void push(int v) {
        if(cap == tos+1) {
            //cout << "overflow.." << endl;
            //expand dynamically
            int newCap = 2 * cap;
            int *newArray = new int[newCap];
            for(int i = 0; i < cap; i++) {
                newArray[i] = a[i];
            }
            delete[] a;
            a = newArray;
            cap = newCap;
            tos++;
            a[tos] = v;
        } else {
            tos++;
            a[tos] = v;
        }
    } 
    void pop() {
        if(tos == -1) {
            cout << "underflow.." << endl;
        } else {
            tos--;
        }
    }
    int top() {
        if(tos == -1) {
            cout << "underflow.." << endl;
        } else {
            return a[tos];
        }
    }
    bool empty() {
        if(tos = -1) {
            return true;
        } else {
            return false;
        }
    }
    void display() {
        for(int i = 0; i < tos+1; i++) {
            cout << a[i] << " " ;
        }
        cout << endl;
    }

};

int main() {
    Stack s(3);
    s.push(4);
    s.push(5);
    s.push(5);
    s.display();
    s.push(5);
    s.display();
    cout << s.size() << " " << s.cap<< endl;

    return 0;
}