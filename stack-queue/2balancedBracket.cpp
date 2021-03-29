#include<bits/stdc++.h>
using namespace std;

bool match(char c, char o) {
    if(c == ')' && o == '(') return true;
    else if (c == '}' && o == '{') return true;
    else if (c == ']' && o == '[') return true;
    else return false;
}

void balancedBracket(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        //if(opening bracket push)
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else if(s[i] == ')' || s[i] == '}' || s[i] == ']') { //if closing pop
            //pop only when closing has pair to pop
            if (!st.empty() && match(s[i], st.top())) {
                st.pop();
            } else if(st.empty()) { //empty means closing brack is extra
                cout << "unbalanced extra closing bracket";
                return;
            } else { //otherwise it is not matched bracket
                cout << "unmatched extra closing bracket";
                return;
            }
        }
    }
    //still not empty that mean unattended opening bracket
    if(!st.empty()) {
        cout << "extra opening brackets";
    } else {
        cout << "balanced..";
    }
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    string s;
    cin >> s;
    balancedBracket(s);
    cout << endl;
    return 0;
}