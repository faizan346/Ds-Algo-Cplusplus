#include<bits/stdc++.h>
using namespace std;

//make stack using queue and also pop efficient
class Stack {
    public:
    queue<int> q;
    queue<int> helper;
    void push(int v) {
        while(!q.empty()) {
            helper.push(q.front());
            q.pop();
        }
        q.push(v);
        while(!helper.empty()) {
            q.push(helper.front());
            helper.pop();
        }
    }
    void pop() {
        if(empty()) {
            cout << "underflow.." << endl;
            return;
        }
        q.pop();
    }
    int top() {
        if(empty()) {
            cout << "underflow.." << endl;
            return -1;
        }
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
    int size() {
        return q.size();
    }
};

int main() {
    Stack s;
    s.push(32);
    s.push(23);
    s.push(53);
    cout << s.top() << endl;
    s.pop();
     cout << s.top() << endl;
    s.pop();
     cout << s.top() << endl;
    s.pop();
    return 0;
}