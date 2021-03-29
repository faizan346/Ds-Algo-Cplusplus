#include<bits/stdc++.h>
using namespace std;

int cal(int a, int b, char c) {
    if(c == '*') return a * b;
    else if(c == '/') return a / b;
    else if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else return -1;
}

void evaluateAndConvert(stack<string> &prefix, stack<string> &infix, stack<int> &val, char op) {
    int v2 = val.top();
    val.pop();
    int v1 = val.top();
    val.pop();
    val.push(cal(v1, v2, op));

    string b = prefix.top();
    prefix.pop();
    string a = prefix.top();
    prefix.pop();
    string s = op + a + b;
    prefix.push(s);

    b = infix.top();
    infix.pop();
    a = infix.top();
    infix.pop();
    s = '(' + a + op + b + ')';
    infix.push(s);
}

//if you want to do conversion for prefix just start loop from right to left and take 
//first popped operand in stack as a and second as b
void postfixEvaluateConvert(string str) {
    stack<int> val;
    stack<string> infix;
    stack<string> prefix;
    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        if(c >= '0' && c <= '9') { // if number
            val.push(c - '0');
            string s = "";
            s = s + c;
            infix.push(s);
            prefix.push(s);
        } else { //if operator
            evaluateAndConvert(prefix, infix, val, c);
        }
    }
    cout << val.top()<<endl;
    cout << infix.top() << endl;
    cout << prefix.top() << endl;
}
//264*8/+3-
// 2
// ((2+((6*4)/8))-3)
// -+2/*6483
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    string s;
    cin >> s;
    postfixEvaluateConvert(s);
    return 0;
}