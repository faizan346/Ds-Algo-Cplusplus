#include<bits/stdc++.h>
using namespace std;

bool solve(string &a, string &b) {
    int i = 0, j = 0;
    bool f1 = true, f2 = true;
    while(true) {
        int counta = 0;
        int countb = 0;
        char c = a[i];
        while(i < a.size() && c == a[i]) {
            i++;
            counta++;
        }
        
        while(j < b.size() && b[j] == a[i-1]) {
            j++;
            countb++;
        }
        if(countb < counta) return false;
        if(i == a.size() && j == b.size()) return true;
        if(i == a.size() || j == b.size()) return false;
    }
    
}

int main() {
    string a , b;
    cin >> a >> b;
    cout << (solve(a, b) ? "true" : "false") << endl;
}