#include<bits/stdc++.h>
using namespace std;

void dublicateBracket(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        //push everuthing but closing brac
        if(s[i] != ')') {
            st.push(s[i]);
        } else { //when closing braket 
            bool isPop = false;
            //pop until opening bracket
            while(!st.empty() && st.top() != '(') {
                st.pop();
                isPop = true;
            }
            //if no pop that means thse bracket are extra and dublicate.
            if(!isPop) {
                cout << "dublicate Bracket" << endl;
                return;
            }
            st.pop(); //pop opening pair
        }
    }
    cout << "nodublicate found" << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    string s;
    cin >> s;
    dublicateBracket(s);
    return 0;
}