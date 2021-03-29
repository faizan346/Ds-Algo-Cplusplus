#include<bits/stdc++.h>
using namespace std;

//stores min value in min var for the current inputs.
//it uses single stack.
class MinStack {
    public:
    stack<int> s;
    int m;
    void push(int v) {
        if(s.empty()) { // setting up the first min when stack empty
            s.push(v);
            m = v;
        } else if(v >= m) { // if larger value, simple push
            s.push(v);
        } else { // if smaller value, push fake value and store original in min
            s.push(v + v - m ); //this fake value will used to extract older min value
            m = v;
        }
    }
    void pop() {
        if(s.empty()) {
            cout << "underflow..."<< endl;
        } else {
            int t = s.top();
            s.pop();
            if(t < m) { // top has fake value
                m = 2 * m - t; // extract old min value.
            }
        }
    }
    int top() {
        if(s.empty()) {
            cout << "underflow..."<< endl;
            return -1;
        } else {
            int t = s.top();
            if(t < m) { // top has fake value
                return m; //return original value in mid
            } else {
                return t; //else top is original value
            }
        }
    }
    int min() {
        if(s.empty()) {
            cout << "unerflow..." << endl;
            return -1;
        } else {
            return m;
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
    s.min();
    s.pop();
    s.push(3);
    s.push(4);
    cout << s.min() << endl;
    s.push(8);
    cout << s.min() << endl;
    s.push(1);
    cout << s.min() << endl;

    return 0;
}