#include<bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if(c == '*' || c == '/') return 2;
    else return 1;
}

int calc(int a, int b, char c) {
    if(c == '*') return a*b;
    if(c == '/') return a/b;
    if(c == '+') return a+b;
    else return a-b;
}

void evaluate(stack<char> &op, stack<int> &opnd) {
    int b = opnd.top();
    opnd.pop();
    int a = opnd.top();
    opnd.pop();
    char c = op.top();
    op.pop();
    opnd.push(calc(a, b, c));
}

int main() {
    string e;
    getline(cin , e);
    stack<char> op;
    stack<int> opnd;
    for(int i = 0; i < e.size(); i++) {
        char ch = e[i];
        if(ch == ' ') continue;
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while(!op.empty() && precedence(op.top()) >= precedence(ch)) {
                evaluate(op, opnd);
            }
            op.push(ch);
        } else {
            int val = 0;
            while(i < e.size() && e[i] >= '0' && e[i] <= '9') {
                val = val*10 + (e[i] - '0');
                i++;
            }
            opnd.push(val);
            i--;
        }
    }
    while(!op.empty()) {
        evaluate(op, opnd);
    }
    cout << opnd.top() << endl;
    return 0;
}