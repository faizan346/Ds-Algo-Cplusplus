#include<bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int n = 1 << s.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s.size(); j++) {
            if(((1 << j) & i) > 0) {
                cout << s[j];
            }
        }
        cout << endl;
    }
}