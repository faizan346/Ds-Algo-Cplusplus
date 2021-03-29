#include<bits/stdc++.h>
using namespace std;

//make quque using stack and also push efficient
class Queue {
    public:
    stack<int> s;
    stack<int> helper;
    void push(int v) {
       s.push(v);
    }
    void pop() {
        if(empty()) {
            cout << "underflow.." << endl;
            return;
        }
        while(size() > 1) { //pop keke helper mai dalne ka bottom vala chordkr
            helper.push(s.top());
            s.pop();
        }
        s.pop(); // bottom vala hama front haiga pop kro
        while(!helper.empty()) { //helper se sare vapis lane ka
            s.push(helper.top());
            helper.pop();
        }
    }
    int front() {
        if(empty()) {
            cout << "underflow.." << endl;
            return -1;
        }
        while(size() > 1) {
            helper.push(s.top());
            s.pop();
        }
        int f = s.top(); //bottom vale photo keech ke helper mai dalne ka
        s.pop();
        helper.push(f);
        while(!helper.empty()) {
            s.push(helper.top());
            helper.pop();
        }
        return f;
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