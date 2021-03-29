#include<bits/stdc++.h>
using namespace std;

void printDecoded(string code, string print) {
    if(code.size() == 0) {
        cout << print << endl;
        return;
    }
    //here we could backtrack because it could be the case 
    //when we don't call next call as the code is not valid.
    //which we assume to be valid.
    char c = code[0];
    if(c != '0') {
        string remCode = code.substr(1);
        c = 'a' + c - '1';
        printDecoded(remCode, print + c);
    } else {
        return;
    }
    
    if(code.size() >= 2) {
        string remCode = code.substr(2);
        string s = code.substr(0,2);
        int n = (s[0] - '0')*10 + (s[1] - '0');
        if(n <= 26) {
            char c = 'a' + n - 1;
            printDecoded(remCode, print + c);
        }
    }
   
}

int main() {
    string s;
    cin >> s;
    printDecoded(s, "");

    return 0;
}