#include<bits/stdc++.h>
using namespace std;

//make stack using queue and also push efficient
class Stack {
    public:
    queue<int> q;
    queue<int> helper;
    void push(int v) {
        q.push(v);
    }
    void pop() {
        if(empty()) {
            cout << "underflow.." << endl;
            return;
        }
        while(q.size() > 1) { //ek element chodkar sbko nikal
            helper.push(q.front());
            q.pop();
        }
        q.pop(); // akele bache elemetn ko delete maar
        while(!helper.empty()) { //helper se sare eleement vapis daal
            q.push(helper.front());
            helper.pop();
        }
    }
    int top() {
        if(empty()) {
            cout << "underflow.." << endl;
            return -1;
        }
        while(q.size() > 1) {
            helper.push(q.front());
            q.pop();
        }
        int t = q.front(); //isme pop ke bjaye usko save krle return krne ke lye
        helper.push(t); //fir islo bhi helper mai daal
        q.pop(); //q se khalo kr f ko
        while(!helper.empty()) { 
            q.push(helper.front());
            helper.pop();
        }
        return t;
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