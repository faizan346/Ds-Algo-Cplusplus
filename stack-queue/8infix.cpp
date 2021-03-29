#include<bits/stdc++.h>
using namespace std;

int cal(int a, int b, char c) {
    if(c == '*') return a * b;
    else if(c == '/') return a / b;
    else if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else return -1;
}

int precedence(char c) {
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void evaluate(stack<int> &opnd, stack<char> &op) {
    int b = opnd.top();
    opnd.pop();
    int a = opnd.top();
    opnd.pop();
    char c = op.top();
    op.pop();
    int val = cal(a, b, c);
    opnd.push(val);
}

//precedence: * == /  > + == -
//when you puch your operator in stack you should evaluate all the 
//operator which has greater or equal precedence because are suppose to
//calculated first
void infix(string str) {
    stack<int> opnd;
    stack<char> op;
    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        if(c == '(') { //push the opening bracket
            op.push(c);
        } else if(c >= '0' && c <= '9') { //push the operand
            opnd.push(c - '0');
        } else if(c == ')') {
            while(op.top() != '(') { //pop and evaluate till opening bracket
                evaluate(opnd, op); //pop and evaluate is implemented inside this
            }
            op.pop(); //pop the opening bracket when encounter
        } else { //when encounter operator with higher or equal precedence in stack pop and evaluate
            while(!op.empty() && op.top() != '(' && precedence(c) <= precedence(op.top())) {
                evaluate(opnd, op);
            }
            op.push(c); //push the curr operator to stack
        }
    }
    //pop and evaluate remaining operator;
    while(!op.empty()) {
        evaluate(opnd, op);
    }
    cout << opnd.top() << endl;
}
//3+(2+2*6/3*(2+2))
//21
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    string s;
    cin >> s;
    infix(s);
    return 0;
}