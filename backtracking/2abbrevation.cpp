#include<bits/stdc++.h>
using namespace std;

void printAbbrevations(string str, string print, int count) {
    if(str.size() == 0) {
        if(count != 0) {
            print = print + (char)(count + '0');
        }
        cout << print << endl;
        return;
    }

    string s = str.substr(0,1);
    string rem = str.substr(1);
    if(count != 0) {
        s = (char)(count + '0') + s;
    }
    printAbbrevations(rem, print + s, 0);
    printAbbrevations(rem, print, count + 1);
}

int main() {
    string s;
    cin >> s;
    printAbbrevations(s, "", 0);
    return 0;
}