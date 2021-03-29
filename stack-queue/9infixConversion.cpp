#include<bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

void conversion(stack<string> &prefix, stack<string> &postfix, stack<char> &op) {
    char c = op.top();
    op.pop();
    string b = prefix.top();
    prefix.pop();
    string a = prefix.top();
    prefix.pop();
    string s = c + a + b;
    prefix.push(s);
    b = postfix.top();
    postfix.pop();
    a = postfix.top();
    postfix.pop();
    s = a + b + c;
    postfix.push(s);
}

void infixConversion(string str) {
    stack<char> op;
    stack<string> prefix;
    stack<string> postfix;
    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        if(c == '(') { 
            op.push(c);
        } else if((c >= '0' && c <= '9') || (c >='a' && c<='z')) {
            string s = "";
            s = s + c;
            prefix.push(s);
            postfix.push(s);
        } else if(c == ')') {
            while(op.top() != '(') { 
                conversion(prefix, postfix, op); 
            }
            op.pop(); 
        } else {
            while(!op.empty() && op.top() != '(' && precedence(c) <= precedence(op.top())) {
                conversion(prefix, postfix, op);
            }
            op.push(c); 
        }
    }

    while(!op.empty()) {
       conversion(prefix, postfix, op);
    }
    cout << postfix.top() << endl;
    cout << prefix.top() << endl;
}
//a+(b+c*d/e*(f+g))
// abcd*e/fg+*++
// +a+b*/*cde+fg
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    string s;
    cin >> s;
    infixConversion(s);
    return 0;
}