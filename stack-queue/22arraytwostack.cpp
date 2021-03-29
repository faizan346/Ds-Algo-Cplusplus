#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int tos1;
    int tos2;
    int cap;
    int *a;
    Stack(int capacity = 10) {
        cap = capacity;
        a = new int[cap];
        tos1 = -1;
        tos2 = cap;
    }
    //stack1----------------
    int size1() {
        return tos1+1;
    }
    void push1(int v) {
        if(tos2 == tos1 + 1) {
            cout << "overflow.." << endl;
        } else {
            tos1++;
            a[tos1] = v;
        }
    } 
    void pop1() {
        if(size1() == 0) {
            cout << "underflow.." << endl;
        } else {
            tos1--;
        }
    }
    int top1() {
        if(size1() == 0) {
            cout << "underflow.." << endl;
        } else {
            return a[tos1];
        }
        return -1;
    }
    bool empty1() {
        if(size1() == 0) return true;
        else return false;
    }
    void display1() {
        for(int i = 0; i < tos1+1; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    //stack2-------------------
    int size2() {
        return cap - tos2;
    }
    void push2(int v) {
        if(tos2 - 1 == tos1) {
            cout << "overflow.." << endl;
        } else {
            tos2--;
            a[tos2] = v;
        }
    } 
    void pop2() {
        if(size2() == 0) {
            cout << "underflow.." << endl;
        } else {
            tos2++;
        }
    }
    int top2() {
        if(size2() == 0) {
            cout << "underflow.." << endl;
        } else {
            return a[tos2];
        }
        return -1;
    }
    bool empty2() {
        if(size2() == 0) return true;
        else return false;
    }
    void display2() {
        for(int i = cap-1; i >= tos2; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Stack s(5);
    s.top1();
    s.top2();
    s.push1(2);
    s.push1(3);
    s.push1(5);
    s.display1();
    cout << s.top1() << endl;
    s.pop1();
    s.display1();
    s.push2(2);
    s.push2(3);
    s.push2(5);
    s.push1(4);
    s.display2();
     cout << s.top2() << endl;
    s.pop2();
    s.display2();

    return 0;
}