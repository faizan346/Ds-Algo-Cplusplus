#include<bits/stdc++.h>
using namespace std;

void calcAndStore(stack<int> &opnd, stack<char> &opst, char &op, int &sign, int &val) {
    val *= (sign == INT_MAX) ? 1 : -1;
    sign = INT_MAX;
    if(op == '*' || op == '/') {
        if(op == '*') val *= opnd.top();
        else val = opnd.top() / val;
        opnd.pop();
        op = '+';
    }
    opnd.push(val);
}

int main() {
    string s;
    cin >> s;
    
    stack<int> opnd; // it stores opnd aswell as sign before paranthesis
    stack<char> opst;
    char op = '+';
    int sign = INT_MAX;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '-' || c == '+') {
            if(c == '-') sign = INT_MIN;
        } else if(c >= '0' && c <= '9') {
            int val = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                val = val*10 + (s[i] - '0');
                i++;
            }
            i--;
            calcAndStore(opnd, opst, op, sign, val);
        } else if(c == '(') {
            opnd.push(sign);
            opst.push(op);
            op = '+';
            sign = INT_MAX;
        } else if(c == ')') {
            int val = 0;
            while(opnd.top() != INT_MAX && opnd.top() != INT_MIN) {
                val += opnd.top();
                opnd.pop();
            }
            sign = opnd.top();
            opnd.pop();
            if(!opst.empty()) {
                op = opst.top();
                opst.pop();
            }
            calcAndStore(opnd, opst, op, sign, val);
        } else { // c == *, /
            op = c;
        }
    }
    int ans = 0;
    while(!opnd.empty()) {
        ans += opnd.top();
        opnd.pop();
    }
    cout << ans << endl;
    return 0;
}