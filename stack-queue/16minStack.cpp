#include<bits/stdc++.h>
using namespace std;

//stores min at top of in minstack for the current inputs.
class MinStack {
    public:
    stack<int> s;
    stack<int> mins;
    void push(int v) {
        s.push(v);
        if(mins.empty() || v <= mins.top()) {
            mins.push(v);
        }
    }
    void pop() {
        int t = s.top();
        s.pop();
        if(t == mins.top()) {
            mins.pop();
        }
    }
    int top() {
        if(s.empty()) {
            cout << "underflow..."<< endl;
        } else {
            return s.top();
        }
    }
    int min() {
        if(s.empty()) {
            cout << "unerflow..." << endl;
            return -1;
        } else {
            return mins.top();
        }
    }

    bool empty() {
        return s.empty();
    }
    int size() {
        return s.size();
    }
};

int main() {
    MinStack s;
    s.push(3);
    s.push(4);
    s.push(8);
    s.push(1);

    return 0;
}