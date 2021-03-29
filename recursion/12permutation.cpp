#include<bits/stdc++.h>
using namespace std;

void printPermutation(string s, string print) {
    if(s.size() == 0) {
        cout << print << endl;
        return;
    }
    for(int i = 0; i < s.size(); i++) {
        string c;
        string reduceString;
        c = s.substr(i, 1);
        reduceString = s.substr(0,i) + s.substr(i+1);
        printPermutation(reduceString, print + c );
    }
   
}

int main() {
    string s;
    cin >> s;
    printPermutation(s, "");
    return 0;
}