#include<bits/stdc++.h>
using namespace std;

//make quque using stack and also pop efficient
class Queue {
    public:
    stack<int> s;
    stack<int> helper;
    void push(int v) {
        while(!s.empty()) {
            helper.push(s.top());
            s.pop();
        }
        s.push(v);
        while(!helper.empty()) {
            s.push(helper.top());
            helper.pop();
        }
    }
    void pop() {
        if(empty()) {
            cout << "underflow.." << endl;
            return;
        }
        s.pop();
    }
    int front() {
        if(empty()) {
            cout << "underflow.." << endl;
            return -1;
        }
        return s.top();
    }
    bool empty() {
        return s.empty();
    }
    int size() {
        return s.size();
    }
};

int main() {
    Queue s;
    s.push(32);
    s.push(23);
    s.push(53);
    cout << s.front() << endl;
    s.pop();
    cout << s.front() << endl;
    s.pop();
    cout << s.front() << endl;
    s.pop();
    return 0;
}