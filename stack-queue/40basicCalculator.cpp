#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<int> state; // it save the accumulated sum and the sign before brackets and helps to solve them separetely 
    int sum = 0;
    int val = 0;
    int sign = +1;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c >= '0' && c <= '9') {
            int val = 0;
            while(i < s.length() && s[i] >= '0' && s[i] <= '9') { // fetched the whole number
                val = val*10 + (s[i] - '0');
                i++;
            }
            i--;                // because i move one step ahead 
            val = val * sign;   // multiply by its sign
            sign = +1;          // change sign to default
            sum += val;         // add curr num val to sum
        } else if(c == '(') {   // start of new state
            state.push(sum);    // save sum to state
            state.push(sign);   // save sign to state
            sum = 0;            // change to default 0
            sign = +1;          // change to default
        } else if(c == ')') {   // end of curr state and merging result with prev states
            sum *= state.top(); // sign fetched
            state.pop();
            sum += state.top(); // added to the stored sum state.
            state.pop();
        } else if(c == '-') {
            sign *= -1;         // when negetive comes then only we reverse sign
        }
    }
    cout << sum << endl;
    return 0;
}